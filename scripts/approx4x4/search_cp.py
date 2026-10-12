#!/usr/bin/env python3
"""CP-ALS search for low-rank *approximate* <n,n,n> multiplication tensors.

This is the numerical step of Smirnov's method (least-squares minimisation of
the target function S1, eq. (3) of the paper) combined with the alternating
solution of the three linear sub-systems he describes.  The difference from a
plain CP decomposition is that we are happy with a nonzero residual: we want
the *smallest rank R* whose best approximation keeps the final matrix product
inside the error budget.

Usage:
    python3 scripts/approx4x4/search_cp.py --n 4 --ranks 40 42 44 46 48 --restarts 40
"""

from __future__ import annotations

import argparse
import json
import os
import sys
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from tensor_utils import matmul_tensor, rel_error  # noqa: E402


def als(T, R, a=None, b=None, c=None, seed=0, iters=600, tol=1e-13, verbose=False):
    """Alternating least squares for T ~ sum_r a_r (x) b_r (x) c_r."""
    N = T.shape[0]
    rng = np.random.default_rng(seed)
    if a is None:
        a = rng.standard_normal((R, N))
    if b is None:
        b = rng.standard_normal((R, N))
    if c is None:
        c = rng.standard_normal((R, N))
    T1 = T.reshape(N, N * N).T          # (N*N, N) : rows (v,w), cols u
    T2 = T.transpose(1, 0, 2).reshape(N, N * N).T
    T3 = T.transpose(2, 0, 1).reshape(N, N * N).T
    prev = np.inf
    for it in range(iters):
        M = np.einsum("rv,rw->vwr", b, c).reshape(N * N, R)
        a = np.linalg.lstsq(M, T1, rcond=None)[0]
        M = np.einsum("ru,rw->uwr", a, c).reshape(N * N, R)
        b = np.linalg.lstsq(M, T2, rcond=None)[0]
        M = np.einsum("ru,rv->uvr", a, b).reshape(N * N, R)
        c = np.linalg.lstsq(M, T3, rcond=None)[0]
        err = np.linalg.norm(T - np.einsum("ru,rv,rw->uvw", a, b, c))
        if verbose and it % 50 == 0:
            print(f"    it {it:4d}  ||res|| = {err:.6e}")
        if abs(prev - err) <= tol * max(1.0, err):
            break
        prev = err
    return a, b, c, err


def search(n, ranks, restarts, iters, seed0=0, out=None):
    T = matmul_tensor(n)
    tnorm = np.linalg.norm(T)
    results = []
    for R in ranks:
        best = None
        t0 = time.time()
        for s in range(restarts):
            a, b, c, _ = als(T, R, seed=seed0 + 1000 * R + s, iters=iters)
            e = rel_error(T, a, b, c)
            if best is None or e < best[0]:
                best = (e, a, b, c)
            if best[0] < 1e-12:
                break
        e = best[0]
        results.append({"R": R, "rel_error": e, "seconds": time.time() - t0,
                        "restarts_used": s + 1})
        print(f"R={R:3d}  rel_err={e:.6e}  omega=log_{n}(R)={np.log(R)/np.log(n):.6f}"
              f"  ({s+1} restarts, {time.time()-t0:.1f}s)")
        if out:
            np.savez(os.path.join(out, f"cp_{n}x{n}_{R}.npz"),
                     a=best[1], b=best[2], c=best[3], rel_error=e)
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--ranks", type=int, nargs="+", required=True)
    ap.add_argument("--restarts", type=int, default=20)
    ap.add_argument("--iters", type=int, default=600)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=None)
    args = ap.parse_args()
    if args.out:
        os.makedirs(args.out, exist_ok=True)
    res = search(args.n, args.ranks, args.restarts, args.iters, args.seed, args.out)
    print(json.dumps(res, indent=1))


if __name__ == "__main__":
    main()
