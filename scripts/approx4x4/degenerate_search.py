#!/usr/bin/env python3
"""Explore 'degenerate' initialisations.

Border-rank solutions have wildly scaled, cancelling coefficients (the rank-20
3x3 algorithm uses term norms ~2^42).  Plain ALS never leaves the neighbourhood
of *balanced* solutions, so here we seed it with deliberately unbalanced starts:

  * log-uniform per-factor scales (10^U(-s, s)) applied to random directions;
  * the exact rank-48 solution with per-term gauge scalings before dropping
    terms (gauge leaves the tensor invariant but changes the ALS trajectory).
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
from tensor_utils import alg_to_factors, matmul_tensor  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def loguniform(rng, shape, spread):
    return 10.0 ** rng.uniform(-spread, spread, shape)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ranks", type=int, nargs="+", default=[46])
    ap.add_argument("--restarts", type=int, default=256)
    ap.add_argument("--sweeps", type=int, default=300)
    ap.add_argument("--spread", type=float, default=3.0)
    ap.add_argument("--drop", type=int, default=2)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4", "degen"))
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)

    from fmmgen import load_from_triadset

    T = matmul_tensor(4)
    tn = np.linalg.norm(T)
    N = 16
    rng = np.random.default_rng(args.seed)
    alg = load_from_triadset(os.path.join(ROOT, "assets", "4x4x4_tensor.mpl"), "4x4")
    a48, b48, c48 = alg_to_factors(alg, 4)

    for R in args.ranks:
        S = args.restarts
        A = np.zeros((S, R, N)); B = np.zeros((S, R, N)); C = np.zeros((S, R, N))
        half = S // 2
        # (1) log-uniform random directions
        for s in range(half):
            A[s] = loguniform(rng, (R, N), args.spread) * rng.standard_normal((R, N))
            B[s] = loguniform(rng, (R, N), args.spread) * rng.standard_normal((R, N))
            C[s] = loguniform(rng, (R, N), args.spread) * rng.standard_normal((R, N))
        # (2) gauge-scaled exact 48 with `drop` terms removed
        for s in range(half, S):
            keep = rng.choice(48, size=R, replace=False)
            g1 = loguniform(rng, (R, 1), args.spread)
            g2 = loguniform(rng, (R, 1), args.spread)
            A[s] = a48[keep] / g1
            B[s] = b48[keep] / g2
            C[s] = c48[keep] * (g1 * g2)
        # a few extra copies of the best-known warm solution
        wp = os.path.join(ROOT, "results", "approx4x4", "warm", f"warm_4x4_{R}.npz")
        if os.path.exists(wp):
            d = np.load(wp)
            for s in range(max(0, S - 8), S):
                A[s] = d["a"] * loguniform(rng, (R, 1), args.spread)
                B[s] = d["b"] * loguniform(rng, (R, 1), args.spread)
                C[s] = d["c"] / (A[s] / d["a"] * B[s] / d["b"])
        t0 = time.time()
        a, b, c, err = batched_als(T, R, S, args.sweeps, seed=args.seed + R,
                                   a0=A, b0=B, c0=C)
        print(f"R={R} degen-init rel_err={err:.6e} ({time.time()-t0:.0f}s)", flush=True)
        np.savez(os.path.join(args.out, f"degen_4x4_{R}.npz"), a=a, b=b, c=c, rel_error=err)


if __name__ == "__main__":
    main()
