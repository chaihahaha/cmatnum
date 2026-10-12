#!/usr/bin/env python3
"""Export a numeric rank-R CP solution of the <4,4,4> tensor to the generator's
text format (``algorithms/m_*.txt`` / ``C_*.txt``).

The CP factors ``a``, ``b``, ``c`` (each ``(R, 16)``) are exactly the
coefficient matrices of Smirnov's bilinear description

    C = sum_r <a_r, A> <b_r, B> c_r ,

so ``a``/``b`` become the two linear forms of each ``m_r`` and ``c`` the output
combination.  Each rank-one term is re-gauged (``a_r/s``, ``b_r/t``, ``c_r*s*t``)
so the three factors have comparable magnitude, which keeps the generated
double-precision code well scaled.
"""

from __future__ import annotations

import argparse
import os
import sys
from fractions import Fraction

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

ROOT = os.path.dirname(os.path.dirname(HERE))

#: coefficients are stored as exact rationals with this denominator bound
DEN_BOUND = 10 ** 8


def balance(a, b, c):
    """Per-term gauge fixing: equalise max|c| of the three factors of each term."""
    R, N = a.shape
    A = np.abs(a).max(axis=1)
    B = np.abs(b).max(axis=1)
    C = np.abs(c).max(axis=1)
    eps = 1e-300
    A = np.maximum(A, eps); B = np.maximum(B, eps); C = np.maximum(C, eps)
    beta = (B * B / (C * A)) ** (1.0 / 3.0)
    alpha = beta * A / B
    return a / alpha[:, None], b / beta[:, None], c * (alpha * beta)[:, None]


def rat(x):
    """Nearest rational with a bounded denominator."""
    if x == 0.0:
        return Fraction(0)
    f = Fraction(float(x)).limit_denominator(DEN_BOUND)
    return f if f != 0 else Fraction(0)


def fmt_coeff(f: Fraction) -> str:
    """'num/den' or 'num' (den == 1); the sign is emitted separately."""
    return str(f.numerator) if f.denominator == 1 else f"{f.numerator}/{f.denominator}"


def linear_form(vec, prefix, n, squeeze_eps=0.0):
    parts = []
    for idx, val in enumerate(vec):
        if abs(val) <= squeeze_eps:
            continue
        f = rat(val)
        if f == 0:
            continue
        i, j = divmod(idx, n)
        sym = f"{prefix}_{i + 1}_{j + 1}"
        body = f"{fmt_coeff(abs(f))}*{sym}" if abs(f) != 1 else sym
        if not parts:
            parts.append(("-" if f < 0 else "") + body)
        else:
            parts.append(("-" if f < 0 else "+") + body)
    return "".join(parts) if parts else "0"


def export(a, b, c, n, name, outdir, balance_terms=True, squeeze_eps=0.0):
    a, b, c = (np.asarray(x, dtype=float) for x in (a, b, c))
    if balance_terms:
        a, b, c = balance(a, b, c)
    R = a.shape[0]
    os.makedirs(outdir, exist_ok=True)
    m_path = os.path.join(outdir, f"m_{name}.txt")
    c_path = os.path.join(outdir, f"C_{name}.txt")
    with open(m_path, "w") as f:
        for r in range(R):
            f.write(f"m_{r + 1}=({linear_form(a[r], 'A', n, squeeze_eps)})"
                    f"*({linear_form(b[r], 'B', n, squeeze_eps)}),\n")
    with open(c_path, "w") as f:
        for i in range(n):
            for j in range(n):
                f.write(f"C_{i + 1}_{j + 1}={_out_terms(c[:, i * n + j], n)}\n")
    print(f"wrote {m_path} and {c_path} (rank {R})")
    return m_path, c_path


def _out_terms(col, n):
    parts = []
    for r, val in enumerate(col):
        if val == 0.0:
            continue
        fr = rat(val)
        if fr == 0:
            continue
        body = (f"{fmt_coeff(abs(fr))}*m_{r + 1}" if abs(fr) != 1 else f"m_{r + 1}")
        if not parts:
            parts.append(("-" if fr < 0 else "") + body)
        else:
            parts.append(("-" if fr < 0 else "+") + body)
    return "".join(parts) if parts else "0"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("npz")
    ap.add_argument("--name", required=True)
    ap.add_argument("--n", type=int, default=4)
    ap.add_argument("--outdir", default=os.path.join(ROOT, "algorithms"))
    ap.add_argument("--no-balance", action="store_true")
    args = ap.parse_args()
    d = np.load(args.npz)
    export(d["a"], d["b"], d["c"], args.n, args.name, args.outdir,
           balance_terms=not args.no_balance)


if __name__ == "__main__":
    main()
