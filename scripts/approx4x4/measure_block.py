#!/usr/bin/env python3
"""Macro-block error of a rank-R approximate <4,4,4> algorithm, measured the
same way as src/benchmark.c: max|C_alg - C| / max|C| over uniform [-1,1] input."""
import os, sys, glob
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from tensor_utils import matmul_tensor, cp_tensor

def block_error(a, b, c, n=4, trials=64, seed=1):
    rng = np.random.default_rng(seed); worst = 0.0
    for _ in range(trials):
        A = 2*rng.random((n,n))-1; B = 2*rng.random((n,n))-1
        C = A @ B
        m = (a @ A.ravel()) * (b @ B.ravel())
        Ca = (c.T @ m).reshape(n, n)
        worst = max(worst, np.abs(Ca-C).max()/max(np.abs(C).max(), 1e-300))
    return worst

if __name__ == "__main__":
    T = matmul_tensor(4); tn = np.linalg.norm(T)
    files = sorted(glob.glob(sys.argv[1] if len(sys.argv)>1 else "results/approx4x4/warm/warm_4x4_*.npz"))
    for f in files:
        d = np.load(f); a,b,c = d["a"],d["b"],d["c"]
        R = a.shape[0]
        te = float(np.linalg.norm(T-cp_tensor(a,b,c))/tn)
        be = block_error(a,b,c)
        om = np.log(R+ (0))/np.log(4)
        print(f"{os.path.basename(f):24s} R={R:3d} tensor_err={te:.4e} block_err={be:.4e} omega={om:.5f}")
