#!/usr/bin/env python3
"""Calibrate 'tensor error' vs 'matrix-result error' using the known rank-20
approximate 3x3x3 algorithm (Smirnov 2013, Table 6 evaluated at x = 2^-7).

The benchmark measures ``max|C_approx - C_exact| / max|C_exact|`` on random
inputs, whereas the bilinear (tensor) description has a Frobenius error
``||T - T_R|| / ||T||``.  This script reports both so that the tensor error can
be used as a proxy while searching for a rank-reduced 4x4 algorithm.
"""

from __future__ import annotations

import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from tensor_utils import alg_to_factors, matmul_tensor, rel_error  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

from fmmgen import load_from_txt  # noqa: E402


def matrix_level_error(a, b, c, n, trials=200, seed=0):
    """max|C_approx - C| / max|C| over random inputs (macro-block level)."""
    rng = np.random.default_rng(seed)
    worst = 0.0
    for _ in range(trials):
        A = rng.standard_normal((n, n))
        B = rng.standard_normal((n, n))
        C = A @ B
        Cw = (a @ A.ravel()) * (b @ B.ravel())
        Ca = (c.T @ Cw).reshape(n, n)
        worst = max(worst, np.abs(Ca - C).max() / np.abs(C).max())
    return worst


def main():
    alg = load_from_txt(
        os.path.join(ROOT, "algorithms", "m_3x3.txt"),
        os.path.join(ROOT, "algorithms", "C_3x3.txt"),
        "3x3",
    )
    n = 3
    T = matmul_tensor(n)
    a, b, c = alg_to_factors(alg, n)
    print(f"3x3 rank-20: ||T||_F = {np.linalg.norm(T):.4f}")
    print(f"  tensor rel error   = {rel_error(T, a, b, c):.6e}")
    print(f"  matrix rel error   = {matrix_level_error(a, b, c, n):.6e}")

    # exact 4x4 for reference
    sys.path.insert(0, os.path.join(ROOT, "scripts"))
    from fmmgen import load_from_triadset

    alg4 = load_from_triadset(os.path.join(ROOT, "assets", "4x4x4_tensor.mpl"), "4x4")
    T4 = matmul_tensor(4)
    a4, b4, c4 = alg_to_factors(alg4, 4)
    print(f"4x4 rank-{alg4.rank}:")
    print(f"  tensor rel error   = {rel_error(T4, a4, b4, c4):.6e}")
    print(f"  matrix rel error   = {matrix_level_error(a4, b4, c4, 4):.6e}")


if __name__ == "__main__":
    main()
