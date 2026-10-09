#!/usr/bin/env python3
"""One-off: extract the rank-20 3x3x3 (Smirnov) coefficients from the legacy
generator into the project's ``m_*.txt`` / ``C_*.txt`` description format.

The legacy script hard-codes three 9x20 coefficient matrices (S, T for the two
operand sides and M for the output); we re-serialise them so the unified
generator can consume the algorithm like any other.
"""

import os

import sympy as sp

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LEGACY = os.path.join(ROOT, "scripts", "legacy", "gen_3x3_code.py")
OUT = os.path.join(ROOT, "algorithms")


def load_coefficients():
    src = open(LEGACY).read()
    prefix = src.split("A = [[sp.Symbol")[0]
    ns = {}
    exec(compile(prefix, LEGACY, "exec"), ns)  # noqa: S102 - trusted repo file
    return ns["S_coeffs"], ns["T_coeffs"], ns["M_coeffs"]


def fmt_term(coeff, sym: str) -> str:
    """Render ``coeff*sym`` with an explicit sign (needed to stay unambiguous)."""
    r = sp.Rational(coeff)
    if r == 1:
        return f"+{sym}"
    if r == -1:
        return f"-{sym}"
    if r < 0:
        return f"-{abs(r)}*{sym}"
    return f"+{r}*{sym}"


def main() -> int:
    S, T, M = load_coefficients()
    rank = S.shape[1]

    with open(os.path.join(OUT, "m_3x3.txt"), "w") as f:
        for r in range(rank):
            a_terms = "".join(fmt_term(S[i, r], f"A_{i // 3 + 1}_{i % 3 + 1}")
                              for i in range(9) if S[i, r] != 0)
            b_terms = "".join(fmt_term(T[j, r], f"B_{j // 3 + 1}_{j % 3 + 1}")
                              for j in range(9) if T[j, r] != 0)
            f.write(f"m_{r + 1}=({a_terms.lstrip('+')})*({b_terms.lstrip('+')}),\n")

    with open(os.path.join(OUT, "C_3x3.txt"), "w") as f:
        for k in range(9):
            terms = "".join(fmt_term(M[k, r], f"m_{r + 1}")
                            for r in range(rank) if M[k, r] != 0)
            f.write(f"C_{k // 3 + 1}_{k % 3 + 1}={terms.lstrip('+')},\n")
    print(f"wrote {OUT}/m_3x3.txt and {OUT}/C_3x3.txt (rank {rank})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
