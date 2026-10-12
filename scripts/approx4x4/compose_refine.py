#!/usr/bin/env python3
"""Compose approximate <2,2,2> algorithms into <4,4,4>, then refine with ALS.

This gives a *structured* warm start for the rank-42/36 <4,4,4> problems that is
completely different from the "drop terms from the exact rank-48 solution"
ladder (which stalls at sqrt(48-R)/8).
"""

from __future__ import annotations

import argparse
import itertools
import os
import sys
import time

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from batch_als import batched_als  # noqa: E402
from compose2x2 import STRASSEN7, compose2, load_2x2  # noqa: E402
from tensor_utils import matmul_tensor, rel_error  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--pairs", nargs="+", default=["7,6", "6,7", "6,6", "5,7", "5,6"])
    ap.add_argument("--restarts", type=int, default=128)
    ap.add_argument("--sweeps", type=int, default=400)
    ap.add_argument("--perturb", type=float, default=0.05)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4", "composed"))
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    T4 = matmul_tensor(4)
    rng = np.random.default_rng(args.seed)

    for pair in args.pairs:
        Ko, Ki = (int(x) for x in pair.split(","))
        ao, bo, co = load_2x2(Ko)
        ai, bi, ci = load_2x2(Ki)
        a0, b0, c0 = compose2(ao, bo, co, ai, bi, ci)
        R = a0.shape[0]
        e0 = rel_error(T4, a0, b0, c0)
        S = args.restarts
        A = np.broadcast_to(a0, (S,) + a0.shape).copy()
        B = np.broadcast_to(b0, (S,) + b0.shape).copy()
        C = np.broadcast_to(c0, (S,) + c0.shape).copy()
        # a quarter of the restarts get a stronger kick
        A[: S // 4] += 0.5 * rng.standard_normal((S // 4, R, 16))
        B[: S // 4] += 0.5 * rng.standard_normal((S // 4, R, 16))
        C[: S // 4] += 0.5 * rng.standard_normal((S // 4, R, 16))
        A[S // 4:] += args.perturb * rng.standard_normal(A[S // 4:].shape)
        B[S // 4:] += args.perturb * rng.standard_normal(B[S // 4:].shape)
        C[S // 4:] += args.perturb * rng.standard_normal(C[S // 4:].shape)
        t0 = time.time()
        a, b, c, err = batched_als(T4, R, S, args.sweeps, seed=args.seed + R,
                                   a0=A, b0=B, c0=C)
        print(f"compose {Ko}x{Ki} -> rank {R:3d}: composed={e0:.4e} "
              f"after ALS={err:.4e} ({time.time()-t0:.0f}s)", flush=True)
        np.savez(os.path.join(args.out, f"composed_4x4_{R}_{Ko}_{Ki}.npz"),
                 a=a, b=b, c=c, rel_error=err, rel_error_composed=e0)


if __name__ == "__main__":
    main()
