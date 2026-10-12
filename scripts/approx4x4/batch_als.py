#!/usr/bin/env python3
"""Batched CP-ALS for the <n,n,n> multiplication tensor.

The loss is evaluated in "Gram" form so that thousands of independent restarts
can be optimised at once on the CPU:

    ||T - sum_r a_r (x) b_r (x) c_r||^2 =
        ||T||^2 - 2 sum_r <T, a_r(x)b_r(x)c_r>
                + sum_{r,s} <a_r,a_s><b_r,b_s><c_r,c_s>

Each ALS sweep solves the three linear sub-systems of Smirnov's least-squares
iteration (eq. (3) of the paper) exactly, for every restart at once, using the
standard MTTKRP + normal-equation form so a sweep costs O(S R (N^2 + R^2))
instead of O(S N^2 R^2).
"""

from __future__ import annotations

import numpy as np


def _unfold_contract(T, m1, m2, mode):
    """W[u,r] = sum_{p,q} T[u,p,q] m1[r,p] m2[r,q], batched over restarts."""
    # m1, m2: (S,R,N); T: (N,N,N)
    if mode == 0:
        return np.einsum("uvw,srv,srw->sur", T, m1, m2, optimize=True)
    if mode == 1:
        return np.einsum("uvw,sru,srw->svr", T, m1, m2, optimize=True)
    return np.einsum("uvw,sru,srv->swr", T, m1, m2, optimize=True)


def _gram(m1, m2):
    return np.einsum("sru,squ->srq", m1, m1, optimize=True) * \
           np.einsum("sru,squ->srq", m2, m2, optimize=True)


def _solve(V, Wt, ridge=1e-12):
    """Solve V[s] X[s] = Wt[s] for every restart, with a tiny ridge."""
    R = V.shape[-1]
    tr = np.einsum("srr->s", V) / R
    V = V + (ridge * tr)[:, None, None] * np.eye(R)[None]
    return np.linalg.solve(V, Wt)


def residual2(T, a, b, c, tnorm2=None):
    """Batched squared Frobenius residual; returns (S,) array."""
    if tnorm2 is None:
        tnorm2 = float(np.sum(T * T))
    t1 = np.einsum("sru,uvw,srv,srw->sr", a, T, b, c, optimize=True)
    G = (np.einsum("sru,squ->srq", a, a, optimize=True)
         * np.einsum("srv,sqv->srq", b, b, optimize=True)
         * np.einsum("srw,sqw->srq", c, c, optimize=True))
    return tnorm2 - 2.0 * t1.sum(axis=1) + G.sum(axis=(1, 2))


def batched_als(T, R, S, sweeps=300, seed=0, a0=None, b0=None, c0=None,
                perturb=0.0, verbose=False, tol=1e-15):
    """Best of S restarts (batched).  Returns (a, b, c, rel_err)."""
    N = T.shape[0]
    rng = np.random.default_rng(seed)
    tnorm2 = float(np.sum(T * T))

    def init(x0):
        if x0 is None:
            return rng.standard_normal((S, R, N))
        base = np.asarray(x0, dtype=float)
        if base.ndim == 2:
            base = np.broadcast_to(base, (S,) + base.shape).copy()
        if base.shape[0] != S:
            base = np.resize(base, (S, R, N))
        return base + perturb * rng.standard_normal((S, R, N))

    a, b, c = init(a0), init(b0), init(c0)
    prev = None
    for it in range(sweeps):
        W = _unfold_contract(T, b, c, 0)
        a = _solve(_gram(b, c), np.transpose(W, (0, 2, 1)))
        W = _unfold_contract(T, a, c, 1)
        b = _solve(_gram(a, c), np.transpose(W, (0, 2, 1)))
        W = _unfold_contract(T, a, b, 2)
        c = _solve(_gram(a, b), np.transpose(W, (0, 2, 1)))
        if it % 5 == 4 or it == sweeps - 1:
            res2 = residual2(T, a, b, c, tnorm2)
            i = int(np.argmin(res2))
            if verbose:
                print(f"    sweep {it+1:4d}  best={np.sqrt(max(res2[i],0))/np.sqrt(tnorm2):.6e}"
                      f"  mean={np.sqrt(max(res2.mean(),0))/np.sqrt(tnorm2):.6e}")
            if prev is not None and abs(prev - res2[i]) < tol * tnorm2:
                break
            prev = res2[i]
    res2 = residual2(T, a, b, c, tnorm2)
    i = int(np.argmin(res2))
    return a[i], b[i], c[i], float(np.sqrt(max(res2[i], 0.0)) / np.sqrt(tnorm2))


def main():
    import argparse
    import os
    import sys
    import time

    HERE = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, HERE)
    from tensor_utils import matmul_tensor

    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--ranks", type=int, nargs="+", required=True)
    ap.add_argument("--restarts", type=int, default=500)
    ap.add_argument("--sweeps", type=int, default=300)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=None)
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()
    if args.out:
        os.makedirs(args.out, exist_ok=True)
    T = matmul_tensor(args.n)
    for R in args.ranks:
        t0 = time.time()
        a, b, c, err = batched_als(T, R, args.restarts, args.sweeps,
                                   seed=args.seed, verbose=args.verbose)
        print(f"R={R:3d}  rel_err={err:.6e}  omega={np.log(R)/np.log(args.n):.6f}"
              f"  ({time.time()-t0:.1f}s)")
        if args.out:
            np.savez(os.path.join(args.out, f"cp_{args.n}x{args.n}_{R}.npz"),
                     a=a, b=b, c=c, rel_error=err)


if __name__ == "__main__":
    main()
