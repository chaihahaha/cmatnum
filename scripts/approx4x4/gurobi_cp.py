#!/usr/bin/env python3
"""Global (Gurobi) solver for the best rank-K approximation of a small
matrix-multiplication tensor.

    minimise  || T - sum_{r=1..K} a_r (x) b_r (x) c_r ||_F

The trilinear terms are linearised with two layers of auxiliary variables
(``p = a*b`` and ``q = p*c``), so the model is a non-convex QCQP that Gurobi
solves with spatial branch & bound (``NonConvex=2``).  That is only practical
for small tensors -- <2,2,2> (K up to 7) is the interesting case here, because
composing two approximate <2,2,2> algorithms is the route to a low-rank
<4,4,4> scheme.
"""

from __future__ import annotations

import argparse
import os
import sys
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from tensor_utils import matmul_tensor  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def solve(n, K, bound=4.0, time_limit=600.0, warm=None, mip_gap=1e-4,
          threads=None, verbose=True):
    import gurobipy as gp
    from gurobipy import GRB

    T = matmul_tensor(n)
    N = n * n
    model = gp.Model(f"cp_{n}x{n}_{n}_{K}")
    model.Params.NonConvex = 2
    model.Params.TimeLimit = time_limit
    model.Params.MIPGap = mip_gap
    model.Params.OutputFlag = 1 if verbose else 0
    if threads:
        model.Params.Threads = threads

    a = model.addVars(N, K, lb=-bound, ub=bound, name="a")
    b = model.addVars(N, K, lb=-bound, ub=bound, name="b")
    c = model.addVars(N, K, lb=-bound, ub=bound, name="c")

    # p[u,v,r] = a[u,r]*b[v,r]   (single layer of linearisation)
    p = model.addVars(N, N, K, lb=-bound * bound, ub=bound * bound, name="p")
    model.addConstrs((p[u, v, r] == a[u, r] * b[v, r]
                      for u in range(N) for v in range(N) for r in range(K)),
                     name="ab")
    # sum_r p[u,v,r]*c[w,r] = T[u,v,w]
    e = model.addVars(N, N, N, lb=-GRB.INFINITY, ub=GRB.INFINITY, name="e")
    model.addConstrs((e[u, v, w] == gp.quicksum(p[u, v, r] * c[w, r] for r in range(K)) - T[u, v, w]
                      for u in range(N) for v in range(N) for w in range(N)),
                     name="res")
    model.setObjective(gp.quicksum(e[u, v, w] * e[u, v, w]
                                   for u in range(N) for v in range(N) for w in range(N)),
                       GRB.MINIMIZE)

    if warm is not None:
        wa, wb, wc = warm
        for u in range(N):
            for r in range(K):
                a[u, r].Start = float(wa[r, u])
                b[u, r].Start = float(wb[r, u])
                c[u, r].Start = float(wc[r, u])

    t0 = time.time()
    model.optimize()

    A = np.array([[a[u, r].X for r in range(K)] for u in range(N)]).T
    B = np.array([[b[u, r].X for r in range(K)] for u in range(N)]).T
    C = np.array([[c[u, r].X for r in range(K)] for u in range(N)]).T
    err = float(np.linalg.norm(T - np.einsum("ru,rv,rw->uvw", A, B, C)) / np.linalg.norm(T))
    if verbose:
        print(f"[n={n} K={K}] status={model.Status} bound={model.ObjBound:.6g} "
              f"best={model.ObjVal:.6g} rel_err={err:.6e} ({time.time()-t0:.1f}s)")
    return A, B, C, err, model


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=2)
    ap.add_argument("--ranks", type=int, nargs="+", required=True)
    ap.add_argument("--bound", type=float, default=4.0)
    ap.add_argument("--time-limit", type=float, default=600.0)
    ap.add_argument("--mip-gap", type=float, default=1e-4)
    ap.add_argument("--threads", type=int, default=None)
    ap.add_argument("--warm-dir", default=None)
    ap.add_argument("--warm-file", default=None)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4"))
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    for K in args.ranks:
        warm = None
        if args.warm_file:
            d = np.load(args.warm_file)
            warm = (d["a"], d["b"], d["c"])
        elif args.warm_dir:
            p = os.path.join(args.warm_dir, f"cp_{args.n}x{args.n}x{args.n}_{K}.npz")
            if os.path.isfile(p):
                d = np.load(p)
                warm = (d["a"], d["b"], d["c"])
        A, B, C, err, _ = solve(args.n, K, args.bound, args.time_limit, warm,
                                mip_gap=args.mip_gap, threads=args.threads)
        np.savez(os.path.join(args.out, f"gurobi_{args.n}x{args.n}x{args.n}_{K}.npz"),
                 a=A, b=B, c=C, rel_error=err)


if __name__ == "__main__":
    main()
