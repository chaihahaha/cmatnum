#!/usr/bin/env python3
"""Rank-reduction search with structured warm starts.

Random ALS lands in poor local minima (it does not even recover the trivial
rank-64 or the known rank-48 solution).  This driver instead walks the rank
down one term at a time, starting from a *known* decomposition:

  1. build the exact rank-48 description shipped in assets/4x4x4_tensor.mpl;
  2. to move from R+1 to R terms, generate candidate initialisations by
     dropping one term and by merging a pair of terms into their best rank-one
     approximation (higher-order power method);
  3. refine every candidate (plus fresh random starts) with batched ALS and
     keep the best.

The result is a sequence of improving approximations; the paper's tolerance
budget (20 %) decides how far down in rank we can walk.
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


def hopm1(u, v, w, up, vp, wp, iters=25):
    """Best rank-one approximation of u(x)v(x)w + u'(x)v'(x)w' (vectors)."""
    x, y, z = up.copy(), vp.copy(), wp.copy()
    for _ in range(iters):
        x = (v @ y) * w * (z @ w) + (vp @ y) * wp * (z @ wp)
        nx = np.linalg.norm(x)
        if nx:
            x /= nx
        y = (w @ z) * u * (x @ u) + (wp @ z) * up * (x @ up)
        ny = np.linalg.norm(y)
        if ny:
            y /= ny
        z = (u @ x) * v * (y @ v) + (up @ x) * vp * (y @ vp)
        nz = np.linalg.norm(z)
        if nz:
            z /= nz
    lam = ((u @ x) * (v @ y) * (w @ z) + (up @ x) * (vp @ y) * (wp @ z))
    return lam * x, y, z


def reduced_candidates(a, b, c, rng, n_merge=40, n_drop=0):
    """Candidate (R,3,N) initialisations obtained from an (R+1)-term solution."""
    R1 = a.shape[0]
    out = []
    drops = range(R1) if n_drop <= 0 else rng.choice(R1, size=min(n_drop, R1), replace=False)
    for i in drops:
        keep = [j for j in range(R1) if j != i]
        out.append((a[keep], b[keep], c[keep]))
    for _ in range(n_merge):
        i, j = rng.choice(R1, size=2, replace=False)
        u, v, w = hopm1(a[i], b[i], c[i], a[j], b[j], c[j])
        keep = [k for k in range(R1) if k != i and k != j]
        aa = np.vstack([a[keep], u[None]])
        bb = np.vstack([b[keep], v[None]])
        cc = np.vstack([c[keep], w[None]])
        out.append((aa, bb, cc))
    return out


def stack_inits(cands, S, R, N, rng, n_random):
    """Pad candidate list with random starts to S restarts -> (S,R,N) triple."""
    a = np.zeros((S, R, N))
    b = np.zeros((S, R, N))
    c = np.zeros((S, R, N))
    k = 0
    for (aa, bb, cc) in cands:
        if k >= S - n_random:
            break
        a[k], b[k], c[k] = aa, bb, cc
        k += 1
    for t in range(k, S):
        a[t] = rng.standard_normal((R, N))
        b[t] = rng.standard_normal((R, N))
        c[t] = rng.standard_normal((R, N))
    return a, b, c


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--top", type=int, default=48)
    ap.add_argument("--bottom", type=int, default=36)
    ap.add_argument("--restarts", type=int, default=256)
    ap.add_argument("--sweeps", type=int, default=250)
    ap.add_argument("--n-random", type=int, default=64)
    ap.add_argument("--n-merge", type=int, default=100)
    ap.add_argument("--perturb", type=float, default=1e-3)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4"))
    ap.add_argument("--load", default=None, help="start from saved npz instead")
    args = ap.parse_args()

    n, N = args.n, args.n * args.n
    T = matmul_tensor(n)
    tnorm = np.linalg.norm(T)
    rng = np.random.default_rng(args.seed)
    os.makedirs(args.out, exist_ok=True)

    if args.load:
        d = np.load(args.load)
        a, b, c = d["a"], d["b"], d["c"]
        err = float(d["rel_error"])
        R = a.shape[0]
    else:
        from fmmgen import load_from_triadset

        alg = load_from_triadset(os.path.join(ROOT, "assets", "4x4x4_tensor.mpl"), "4x4")
        a, b, c = alg_to_factors(alg, n)
        R = a.shape[0]
        pred = np.einsum("ru,rv,rw->uvw", a, b, c, optimize=True)
        err = float(np.linalg.norm(T - pred) / tnorm)
    print(f"start R={R} rel_err={err:.4e}", flush=True)

    while R > args.bottom:
        t0 = time.time()
        cands = reduced_candidates(a, b, c, rng, n_merge=args.n_merge)
        S = args.restarts
        A0, B0, C0 = stack_inits(cands, S, R - 1, N, rng, args.n_random)
        A0 = A0 + args.perturb * rng.standard_normal(A0.shape)
        B0 = B0 + args.perturb * rng.standard_normal(B0.shape)
        C0 = C0 + args.perturb * rng.standard_normal(C0.shape)
        a, b, c, err = batched_als(T, R - 1, S, args.sweeps, seed=args.seed + R,
                                   a0=A0, b0=B0, c0=C0)
        R = R - 1
        print(f"R={R} rel_err={err:.6e} omega={np.log(R)/np.log(n):.6f} "
              f"({time.time()-t0:.1f}s, {len(cands)} candidates + {args.n_random} random)",
              flush=True)
        np.savez(os.path.join(args.out, f"warm_{n}x{n}_{R}.npz"),
                 a=a, b=b, c=c, rel_error=err)


if __name__ == "__main__":
    main()
