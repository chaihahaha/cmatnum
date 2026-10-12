"""Tensor helpers for studying approximate (border-rank) matrix-multiplication
algorithms, following the method of Smirnov (2013), see
``assets/smirnov_approx_matmul.pdf``.

Conventions
-----------
For the <n,n,n> product ``C = A*B`` the structure tensor is

    T[(i,j), (j,k), (i,k)] = 1        (i,j,k = 0..n-1)

so that ``sum_uv T[u,v,w] A_flat[u] B_flat[v] = C_flat[w]``.

A rank-R (approximate) algorithm is a CP decomposition

    T ~ sum_r a_r (x) b_r (x) c_r

with ``a_r``/``b_r`` the coefficients of the two linear forms and ``c_r`` the
coefficients of the output combination -- exactly the information stored in
``algorithms/m_*.txt`` / ``C_*.txt``.
"""

from __future__ import annotations

import os
import sys

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))

_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def matmul_tensor(n: int) -> np.ndarray:
    """Sparse structure tensor of <n,n,n> matrix multiplication."""
    N = n * n
    T = np.zeros((N, N, N))
    for i in range(n):
        for j in range(n):
            for k in range(n):
                T[i * n + j, j * n + k, i * n + k] = 1.0
    return T


def cp_tensor(a: np.ndarray, b: np.ndarray, c: np.ndarray) -> np.ndarray:
    """Rebuild sum_r a[r] (x) b[r] (x) c[r] (a, b, c are (R, N))."""
    return np.einsum("ru,rv,rw->uvw", a, b, c)


def rel_error(T: np.ndarray, a: np.ndarray, b: np.ndarray, c: np.ndarray) -> float:
    """Relative Frobenius error ||T - sum a(x)b(x)c|| / ||T||."""
    return float(np.linalg.norm(T - cp_tensor(a, b, c)) / np.linalg.norm(T))


def alg_to_factors(alg, n: int):
    """Convert an :class:`fmmgen.algorithm.Algorithm` into (a, b, c) arrays."""
    import sympy as sp

    N = n * n

    def form_to_vec(expr, prefix):
        vec = np.zeros(N)
        expr = sp.expand(expr)
        for term in sp.Add.make_args(expr):
            coeff, syms = term.as_coeff_Mul()
            name = str(syms)
            assert name.startswith(prefix), (name, prefix)
            _, i, j = name.split("_")
            vec[(int(i) - 1) * n + (int(j) - 1)] = float(coeff)
        return vec

    R = alg.rank
    a = np.stack([form_to_vec(f, "A") for f in alg.a_forms])
    b = np.stack([form_to_vec(f, "B") for f in alg.b_forms])
    c = np.zeros((R, N))
    for (i, j), terms in alg.c_terms.items():
        for r, coeff in terms:
            c[r, (i - 1) * n + (j - 1)] += float(coeff)
    return a, b, c
