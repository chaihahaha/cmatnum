#!/usr/bin/env python3
"""Best-effort multi-strategy search for low-rank <4,4,4> approximations.

Combines every warm start we have (drop-ladder, 2x2x2 composition, random,
"respawn" of single terms) in one batched ALS run per rank, and reports both the
tensor Frobenius error and the macro-block error used by src/benchmark.c.
"""

from __future__ import annotations

import argparse
import os
import sys
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, ".."))

from batch_als import batched_als  # noqa: E402
from compose2x2 import STRASSEN7, compose2, load_2x2  # noqa: E402
from tensor_utils import alg_to_factors, cp_tensor, matmul_tensor, rel_error  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def block_error(a, b, c, n=4, trials=64, seed=1):
    rng = np.random.default_rng(seed)
    worst = 0.0
    for _ in range(trials):
        A = 2 * rng.random((n, n)) - 1
        B = 2 * rng.random((n, n)) - 1
        C = A @ B
        m = (a @ A.ravel()) * (b @ B.ravel())
        Ca = (c.T @ m).reshape(n, n)
        worst = max(worst, np.abs(Ca - C).max() / max(np.abs(C).max(), 1e-300))
    return worst


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ranks", type=int, nargs="+", default=[43, 44, 45])
    ap.add_argument("--restarts", type=int, default=768)
    ap.add_argument("--sweeps", type=int, default=400)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4", "final"))
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)

    from fmmgen import load_from_triadset

    T = matmul_tensor(4)
    tn = np.linalg.norm(T)
    N = 16
    rng = np.random.default_rng(args.seed)
    alg = load_from_triadset(os.path.join(ROOT, "assets", "4x4x4_tensor.mpl"), "4x4")
    a48, b48, c48 = alg_to_factors(alg, 4)
    comp = {}

    def composed(Ko, Ki):
        key = (Ko, Ki)
        if key not in comp:
            comp[key] = compose2(*STRASSEN7 if Ko == 7 else load_2x2(Ko),
                                 *(STRASSEN7 if Ki == 7 else load_2x2(Ki)))
        return comp[key]

    for R in args.ranks:
        S = args.restarts
        A = np.zeros((S, R, N)); B = np.zeros((S, R, N)); C = np.zeros((S, R, N))
        k = 0
        # (a) gauge-scaled drops from the exact rank-48 solution
        for _ in range(S // 4):
            keep = rng.choice(48, size=R, replace=False)
            A[k], B[k], C[k] = a48[keep], b48[keep], c48[keep]
            k += 1
        # (b) merges of pairs (best rank-1 fit), plus drops
        for _ in range(S // 8):
            keep = rng.choice(48, size=R, replace=False)
            A[k], B[k], C[k] = a48[keep], b48[keep], c48[keep]
            i, j = rng.choice(R, size=2, replace=False)
            A[k, i] = A[k, i] + 0.3 * A[k, j]
            B[k, i] = B[k, i] + 0.3 * B[k, j]
            C[k, i] = C[k, i] + 0.3 * C[k, j]
            k += 1
        # (c) 2x2x2 compositions, if the rank matches
        for (Ko, Ki), (ca, cb, cc) in comp.items():
            if ca.shape[0] == R and k < S:
                A[k], B[k], C[k] = ca, cb, cc
                k += 1
        # (d) the previous best-known solution for this rank, perturbed
        prev = None
        for cand in (os.path.join(ROOT, "results", "approx4x4", "warm", f"warm_4x4_{R}.npz"),
                     os.path.join(ROOT, "results", "approx4x4", "final", f"final_4x4_{R}.npz")):
            if os.path.isfile(cand):
                prev = np.load(cand)
                for _ in range(S // 8):
                    if k >= S:
                        break
                    A[k] = prev["a"] + 0.1 * rng.standard_normal((R, N))
                    B[k] = prev["b"] + 0.1 * rng.standard_normal((R, N))
                    C[k] = prev["c"] + 0.1 * rng.standard_normal((R, N))
                    k += 1
                break
        # (e) "respawn": take the current best and replace one term at random
        if prev is not None:
            for _ in range(S // 8):
                if k >= S:
                    break
                A[k] = prev["a"]; B[k] = prev["b"]; C[k] = prev["c"]
                i = rng.integers(R)
                A[k, i] = rng.standard_normal(N)
                B[k, i] = rng.standard_normal(N)
                C[k, i] = rng.standard_normal(N)
                k += 1
        # (f) the rest: pure random
        while k < S:
            A[k] = rng.standard_normal((R, N))
            B[k] = rng.standard_normal((R, N))
            C[k] = rng.standard_normal((R, N))
            k += 1

        t0 = time.time()
        a, b, c, err = batched_als(T, R, S, args.sweeps, seed=args.seed + R,
                                   a0=A, b0=B, c0=C)
        be = block_error(a, b, c)
        print(f"rank {R:3d}: tensor_err={err:.4e}  block_err={be:.4e}  "
              f"omega={np.log(R)/np.log(4):.5f}  ({time.time()-t0:.0f}s, {S} restarts)",
              flush=True)
        np.savez(os.path.join(args.out, f"final_4x4_{R}.npz"), a=a, b=b, c=c,
                 rel_error=err, block_error=be)


if __name__ == "__main__":
    main()
