#!/usr/bin/env python3
"""Build <4,4,4> algorithms by composing two <2,2,2> algorithms.

The composition rule: partition A, B, C into 2x2 blocks of 2x2 matrices.  An
*outer* rank-R_o algorithm multiplies the block matrices, and every one of its
R_o block products is evaluated by an *inner* rank-R_i algorithm, giving a
rank R_o*R_i algorithm for <4,4,4>.  Using an approximate (rank-6/5) <2,2,2> in
one or both slots is how a rank well below the border rank 48/46 is reached.

Coefficient layout (all matrices are (R, 16) with the flat index i*4+j):

    A index (I,J) = (2p+u, 2q+v)   outer block (p,q), inner entry (u,v)
    a[(tau,sigma), (I,J)] = alpha_o[tau,(p,q)] * a_i[sigma, (u,v)]
    b[(tau,sigma), (J,K)] = beta_o[tau,(q,r)]  * b_i[sigma, (v,w)]
    c[(tau,sigma), (I,K)] = gamma_o[tau,(p,r)] * c_i[sigma, (u,w)]
"""

from __future__ import annotations

import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

ROOT = os.path.dirname(os.path.dirname(HERE))

#: Strassen's rank-7 decomposition of <2,2,2>, as (a, b, c) with flat 2x2 index
STRASSEN7 = (
    np.array([
        [1, 0, 0, 1],     # a11 + a22
        [0, 0, 1, 1],     # a21 + a22
        [1, 0, 0, 0],     # a11
        [0, 0, 0, 1],     # a22
        [1, 1, 0, 0],     # a11 + a12
        [-1, 0, 1, 0],    # a21 - a11
        [0, 1, 0, -1],    # a12 - a22
    ], dtype=float),
    np.array([
        [1, 0, 0, 1],     # b11 + b22
        [1, 0, 0, 0],     # b11
        [0, 1, 0, -1],    # b12 - b22
        [-1, 0, 1, 0],    # b21 - b11
        [0, 0, 0, 1],     # b22
        [1, 1, 0, 0],     # b11 + b12
        [0, 0, 1, 1],     # b21 + b22
    ], dtype=float),
    np.array([
        [1, 0, 0, 1],     # c11 + c22
        [0, 0, 1, -1],    # c21 - c22
        [0, 1, 0, 1],     # c12 + c22
        [1, 0, 1, 0],     # c11 + c21
        [-1, 1, 0, 0],    # c12 - c11
        [0, 0, 0, 1],     # c22
        [1, 0, 0, 0],     # c11
    ], dtype=float),
)


def compose2(ao, bo, co, ai, bi, ci, n=2):
    """Compose outer (ao,bo,co) with inner (ai,bi,ci) into a <4,4,4> algorithm."""
    Ro = ao.shape[0]
    Ri = ai.shape[0]
    R = Ro * Ri
    a = np.zeros((R, 16))
    b = np.zeros((R, 16))
    c = np.zeros((R, 16))
    k = 0
    for tau in range(Ro):
        for sig in range(Ri):
            for p in range(n):
                for q in range(n):
                    av = ao[tau, p * n + q]
                    if av == 0.0:
                        continue
                    for u in range(n):
                        for v in range(n):
                            iv = ai[sig, u * n + v]
                            if iv:
                                a[k, (2 * p + u) * 4 + (2 * q + v)] += av * iv
            for q in range(n):
                for r in range(n):
                    bv = bo[tau, q * n + r]
                    if bv == 0.0:
                        continue
                    for v in range(n):
                        for w in range(n):
                            iv = bi[sig, v * n + w]
                            if iv:
                                b[k, (2 * q + v) * 4 + (2 * r + w)] += bv * iv
            for p in range(n):
                for r in range(n):
                    cv = co[tau, p * n + r]
                    if cv == 0.0:
                        continue
                    for u in range(n):
                        for w in range(n):
                            iv = ci[sig, u * n + w]
                            if iv:
                                c[k, (2 * p + u) * 4 + (2 * r + w)] += cv * iv
            k += 1
    return a, b, c


def load_2x2(K, results=None):
    results = results or os.path.join(ROOT, "results", "approx4x4")
    if K == 7:
        return STRASSEN7
    d = np.load(os.path.join(results, f"cp_2x2x2_{K}.npz"))
    return d["a"], d["b"], d["c"]


def check_2x2(a, b, c, tol=1e-9):
    rng = np.random.default_rng(0)
    worst = 0.0
    for _ in range(50):
        A = rng.standard_normal((2, 2))
        B = rng.standard_normal((2, 2))
        m = (a @ A.ravel()) * (b @ B.ravel())
        Ca = (c.T @ m).reshape(2, 2)
        worst = max(worst, np.abs(Ca - A @ B).max())
    return worst


if __name__ == "__main__":
    import itertools
    from tensor_utils import matmul_tensor, rel_error

    T4 = matmul_tensor(4)
    print("strassen7 self-check err =", check_2x2(*STRASSEN7))
    for Ko, Ki in itertools.product([7, 6, 5, 4], repeat=2):
        try:
            ao, bo, co = load_2x2(Ko)
            ai, bi, ci = load_2x2(Ki)
        except FileNotFoundError:
            continue
        a, b, c = compose2(ao, bo, co, ai, bi, ci)
        print(f"outer rank {Ko} x inner rank {Ki} = {Ko*Ki:3d}  tensor rel err {rel_error(T4,a,b,c):.4e}")
