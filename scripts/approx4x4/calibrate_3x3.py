#!/usr/bin/env python3
"""Calibration on the 3x3x3 tensor: how fast does the error grow when the rank
drops below the border rank (20)?

The rank-20 3x3x3 algorithm is Smirnov's border-rank scheme; rank 19..16 are
obtained by dropping terms and re-optimising with batched ALS.  The growth rate
is the best available predictor for what a rank-reduced <4,4,4> scheme can do
(border rank 46).
"""

from __future__ import annotations

import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, ".."))

from batch_als import batched_als  # noqa: E402
from tensor_utils import alg_to_factors, matmul_tensor, rel_error  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def main():
    from fmmgen import load_from_txt

    T = matmul_tensor(3)
    alg = load_from_txt(os.path.join(ROOT, "algorithms", "m_3x3.txt"),
                        os.path.join(ROOT, "algorithms", "C_3x3.txt"), "3x3")
    a0, b0, c0 = alg_to_factors(alg, 3)
    print(f"3x3 rank 20 (Smirnov): tensor rel err {rel_error(T, a0, b0, c0):.6e}", flush=True)
    rng = np.random.default_rng(0)
    S = 128
    for drop in range(1, 7):
        R = 20 - drop
        keep = np.stack([np.delete(np.arange(20), rng.choice(20, drop, replace=False))
                         for _ in range(S)])
        A = a0[keep].copy()
        B = b0[keep].copy()
        C = c0[keep].copy()
        A += 0.05 * rng.standard_normal(A.shape)
        B += 0.05 * rng.standard_normal(B.shape)
        C += 0.05 * rng.standard_normal(C.shape)
        a, b, c, e = batched_als(T, R, S, 400, seed=drop, a0=A, b0=B, c0=C)
        a2, b2, c2, e2 = batched_als(T, R, 256, 400, seed=100 + drop)
        print(f"3x3 rank {R:2d}: drop-init {e:.4e}   random {e2:.4e}", flush=True)
        np.savez(os.path.join(ROOT, "results", "approx4x4", f"cp_3x3_{R}.npz"),
                 a=a, b=b, c=c, rel_error=e)


if __name__ == "__main__":
    main()
