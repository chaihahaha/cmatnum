#!/usr/bin/env python3
"""Ridge-continuation ALS.

Plain ALS stalls at a "single rank-one residual" local minimum (dropping one of
the 64 naive monomials gives exactly 1/8 = 12.5 %).  Border-rank solutions have
*huge* coefficients that cancel, so we optimise a continuation path

    min ||T - sum a(x)b(x)c||^2  +  lambda * sum_r ||a_r||^2+||b_r||^2+||c_r||^2

starting from a large lambda (well-conditioned, small coefficients) and
decreasing it geometrically down to ~0.  The final lambda is tiny, so the
stationary point is a genuine local minimum of the plain residual; the path
just reaches a different one.
"""

from __future__ import annotations

import argparse
import os
import sys
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from batch_als import _gram, _unfold_contract, residual2  # noqa: E402
from tensor_utils import matmul_tensor  # noqa: E402


def als_ridge(T, R, S, a, b, c, lam, sweeps):
    """Run `sweeps` ALS iterations with ridge `lam` (per restart)."""
    N = T.shape[0]
    for _ in range(sweeps):
        W = _unfold_contract(T, b, c, 0)
        V = _gram(b, c) + lam * np.eye(R)[None]
        a = np.linalg.solve(V, np.transpose(W, (0, 2, 1)))
        W = _unfold_contract(T, a, c, 1)
        V = _gram(a, c) + lam * np.eye(R)[None]
        b = np.linalg.solve(V, np.transpose(W, (0, 2, 1)))
        W = _unfold_contract(T, a, b, 2)
        V = _gram(a, b) + lam * np.eye(R)[None]
        c = np.linalg.solve(V, np.transpose(W, (0, 2, 1)))
    return a, b, c


def continuation(T, R, S, lams, sweeps, seed=0, a0=None, b0=None, c0=None,
                 perturb=0.0, tnorm2=None, verbose=False):
    N = T.shape[0]
    rng = np.random.default_rng(seed)
    if tnorm2 is None:
        tnorm2 = float(np.sum(T * T))

    def init(x0):
        if x0 is None:
            return rng.standard_normal((S, R, N))
        base = np.asarray(x0, dtype=float)
        if base.ndim == 2:
            base = np.broadcast_to(base, (S,) + base.shape).copy()
        return base + perturb * rng.standard_normal((S, R, N))

    a, b, c = init(a0), init(b0), init(c0)
    for lam in lams:
        a, b, c = als_ridge(T, R, S, a, b, c, lam, sweeps)
        res2 = residual2(T, a, b, c, tnorm2)
        i = int(np.argmin(res2))
        if verbose:
            print(f"    lam={lam:.1e}  best={np.sqrt(max(res2[i],0))/np.sqrt(tnorm2):.6e}")
    res2 = residual2(T, a, b, c, tnorm2)
    i = int(np.argmin(res2))
    return a[i], b[i], c[i], float(np.sqrt(max(res2[i], 0.0)) / np.sqrt(tnorm2))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--ranks", type=int, nargs="+", required=True)
    ap.add_argument("--restarts", type=int, default=128)
    ap.add_argument("--sweeps", type=int, default=40)
    ap.add_argument("--lams", type=float, nargs="+", default=[1.0, 1e-1, 1e-2, 1e-3, 1e-4])
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--perturb", type=float, default=0.0)
    ap.add_argument("--init-from", default=None)
    ap.add_argument("--out", default=None)
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()
    T = matmul_tensor(args.n)
    a0 = b0 = c0 = None
    if args.init_from:
        d = np.load(args.init_from)
        a0, b0, c0 = d["a"], d["b"], d["c"]
    if args.out:
        os.makedirs(args.out, exist_ok=True)
    for R in args.ranks:
        t0 = time.time()
        a, b, c, err = continuation(T, R, args.restarts, args.lams, args.sweeps,
                                   seed=args.seed, a0=a0, b0=b0, c0=c0,
                                   perturb=args.perturb, verbose=args.verbose)
        print(f"R={R:3d}  rel_err={err:.6e}  omega={np.log(R)/np.log(args.n):.6f}"
              f"  ({time.time()-t0:.1f}s)", flush=True)
        if args.out:
            np.savez(os.path.join(args.out, f"ridge_{args.n}x{args.n}_{R}.npz"),
                     a=a, b=b, c=c, rel_error=err)


if __name__ == "__main__":
    main()
