#!/usr/bin/env python3
"""Structure-aware Gurobi model for a rank-R approximation of <4,4,4>.

Instead of the generic (u,v,w) linearisation this exploits the multiplication
tensor's index structure:

    a[(i,j),r], b[(j,k),r], c[(i,k),r]
    p[(i,j,k),r] = a[(i,j),r] * b[(j,k),r]                       (64R products)
    sum_r p[(i,j,k),r] * c[(i',k'),r] = delta_{ii'} delta_{kk'}   (64*16 equations)

which is 4x smaller than the naive formulation (1024 bilinear equations with R
terms instead of 4096 trilinear ones), small enough for Gurobi's non-convex
spatial branch & bound to make progress on.

Usage:
  python3 scripts/approx4x4/gurobi_4x4.py --rank 43 --warm results/approx4x4/warm/warm_4x4_43.npz \
      --time-limit 1800 --bound 20
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


def main():
    import gurobipy as gp
    from gurobipy import GRB

    ap = argparse.ArgumentParser()
    ap.add_argument("--rank", type=int, required=True)
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--bound", type=float, default=20.0)
    ap.add_argument("--time-limit", type=float, default=1800.0)
    ap.add_argument("--mip-gap", type=float, default=1.0)
    ap.add_argument("--warm", default=None)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4"))
    ap.add_argument("--objective", choices=["frob", "max"], default="frob")
    args = ap.parse_args()

    n, R = args.n, args.rank
    N = n * n
    T = matmul_tensor(n)

    model = gp.Model(f"r{R}_4x4x4")
    model.Params.NonConvex = 2
    model.Params.TimeLimit = args.time_limit
    model.Params.MIPGap = args.mip_gap
    model.Params.OutputFlag = 1
    model.Params.Heuristics = 0.3
    model.Params.Symmetry = 2

    B = args.bound
    a = model.addVars(N, R, lb=-B, ub=B, name="a")
    b = model.addVars(N, R, lb=-B, ub=B, name="b")
    c = model.addVars(N, R, lb=-B, ub=B, name="c")

    def ai(i, j):
        return i * n + j

    # p[(i,j,k), r] = a[(i,j),r] * b[(j,k),r]
    p = model.addVars(n, n, n, R, lb=-B * B, ub=B * B, name="p")
    model.addConstrs((p[i, j, k, r] == a[ai(i, j), r] * b[ai(j, k), r]
                      for i in range(n) for j in range(n) for k in range(n)
                      for r in range(R)), name="ab")

    # residual: sum_r p[(i,j,k),r]*c[(i',k'),r] - delta
    e = model.addVars(n, n, n, n, n, lb=-GRB.INFINITY, ub=GRB.INFINITY, name="e")
    model.addConstrs(
        (e[i, j, k, ip, kp] == gp.quicksum(p[i, j, k, r] * c[ai(ip, kp), r] for r in range(R))
         - (1.0 if (i == ip and k == kp) else 0.0)
         for i in range(n) for j in range(n) for k in range(n)
         for ip in range(n) for kp in range(n)), name="res")

    if args.objective == "frob":
        model.setObjective(gp.quicksum(e[i, j, k, ip, kp] * e[i, j, k, ip, kp]
                                       for i in range(n) for j in range(n) for k in range(n)
                                       for ip in range(n) for kp in range(n)), GRB.MINIMIZE)
    else:
        t = model.addVar(lb=0, ub=GRB.INFINITY, name="t")
        model.addConstrs((t >= e[i, j, k, ip, kp] for i in range(n) for j in range(n)
                          for k in range(n) for ip in range(n) for kp in range(n)), name="abs1")
        model.addConstrs((t >= -e[i, j, k, ip, kp] for i in range(n) for j in range(n)
                          for k in range(n) for ip in range(n) for kp in range(n)), name="abs2")
        model.setObjective(t, GRB.MINIMIZE)

    if args.warm:
        d = np.load(args.warm)
        wa, wb, wc = d["a"], d["b"], d["c"]
        scale = max(np.abs(wa).max(), np.abs(wb).max(), np.abs(wc).max())
        wa, wb, wc = wa / scale, wb / scale, wc / scale
        for u in range(N):
            for r in range(R):
                a[u, r].Start = float(wa[r, u])
                b[u, r].Start = float(wb[r, u])
                c[u, r].Start = float(wc[r, u])
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    for r in range(R):
                        p[i, j, k, r].Start = float(wa[r, ai(i, j)] * wb[r, ai(j, k)])
        print("warm start installed", flush=True)

    t0 = time.time()
    model.optimize()

    A = np.array([[a[u, r].X for r in range(R)] for u in range(N)]).T
    Bv = np.array([[b[u, r].X for r in range(R)] for u in range(N)]).T
    C = np.array([[c[u, r].X for r in range(R)] for u in range(N)]).T
    err = float(np.linalg.norm(T - np.einsum("ru,rv,rw->uvw", A, Bv, C)) / np.linalg.norm(T))
    print(f"[rank {R}] status={model.Status} obj={model.ObjVal:.6g} "
          f"bound={model.ObjBound:.6g} tensor_rel_err={err:.6e} ({time.time()-t0:.0f}s)", flush=True)
    if args.out:
        os.makedirs(args.out, exist_ok=True)
        np.savez(os.path.join(args.out, f"gurobi_4x4_{R}.npz"),
                 a=A, b=Bv, c=C, rel_error=err)


if __name__ == "__main__":
    main()
