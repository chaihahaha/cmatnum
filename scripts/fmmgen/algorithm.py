"""Algebraic descriptions of fast matrix-multiplication algorithms.

An algorithm for <na, nb, nc> (i.e. C[na x nb] = A[na x nc] * B[nc x nb]) is a
rank-R bilinear decomposition

    C[i][j] = sum_r <A_r, A> * <B_r, B> * C_r[i][j]

where the ``A_r``/``B_r`` are the "linear forms" and ``C_r`` the rank-one
output masks.  The project stores these descriptions in two textual forms:

* ``m_*.txt``: one line per rank-one term, ``m_k=(<A form>)*(<B form>)``.
* ``C_*.txt``: one line per output element, ``C_i_j = sum_k c * m_k``.

and, in the original Maple form, as a ``TriadSet`` of ``Triad(A_r, B_r, C_r)``
matrices where ``C = sum_r <A_r,A> <B_r,B> C_r^T``.
"""

from __future__ import annotations

import re
from dataclasses import dataclass, field
from typing import Dict, List, Sequence, Tuple

import sympy as sp


@dataclass
class Algorithm:
    """A rank-R description of a small matrix product.

    ``A`` has ``a_rows x a_cols`` macro-blocks, ``B`` has ``a_cols x b_cols``
    macro-blocks and ``C`` has ``a_rows x b_cols`` macro-blocks.
    """

    name: str
    a_rows: int
    a_cols: int
    b_cols: int
    #: rank-one terms: (A form over A_i_j, B form over B_i_j)
    a_forms: List[sp.Expr] = field(default_factory=list)
    b_forms: List[sp.Expr] = field(default_factory=list)
    #: output: {(i, j): [(rank index, coefficient), ...]}, i/j are 1-based
    c_terms: Dict[Tuple[int, int], List[Tuple[int, sp.Expr]]] = field(default_factory=dict)

    @property
    def rank(self) -> int:
        return len(self.a_forms)

    # ------------------------------------------------------------------ #
    def a_symbols(self) -> List[sp.Symbol]:
        return [sp.Symbol(f"A_{i+1}_{j+1}") for i in range(self.a_rows) for j in range(self.a_cols)]

    def b_symbols(self) -> List[sp.Symbol]:
        return [sp.Symbol(f"B_{i+1}_{j+1}") for i in range(self.a_cols) for j in range(self.b_cols)]

    def c_symbols(self) -> List[sp.Symbol]:
        return [sp.Symbol(f"C_{i+1}_{j+1}") for i in range(self.a_rows) for j in range(self.b_cols)]

    # ------------------------------------------------------------------ #
    def verify(self) -> bool:
        """Symbolically check that the decomposition reproduces A*B."""
        A = sp.Matrix(self.a_rows, self.a_cols, lambda i, j: sp.Symbol(f"A_{i+1}_{j+1}"))
        B = sp.Matrix(self.a_cols, self.b_cols, lambda i, j: sp.Symbol(f"B_{i+1}_{j+1}"))
        target = A * B
        out = sp.zeros(self.a_rows, self.b_cols)
        for r, (af, bf) in enumerate(zip(self.a_forms, self.b_forms)):
            coeff = af * bf
            for (i, j), terms in self.c_terms.items():
                for (ri, c) in terms:
                    if ri == r:
                        out[i - 1, j - 1] += coeff * c
        diff = sp.expand(out - target)
        return all(v == 0 for v in diff)


# ---------------------------------------------------------------------- #
# Parsing helpers
# ---------------------------------------------------------------------- #

_TERM_RE = re.compile(r"([+-]?)\s*(?:(\d+)/(\d+)|(\d+))?\s*\*?\s*([A-Za-z]+_\d+_\d+)")


def _parse_linear_form(text: str, prefix: str) -> sp.Expr:
    """Parse ``-1/8*A_1_1+A_2_3`` style linear forms into a sympy expression."""
    text = text.strip()
    # normalise leading sign so the regex always sees a sign
    if text and text[0] not in "+-":
        text = "+" + text
    pos = 0
    terms = []
    for m in _TERM_RE.finditer(text):
        sign, num, den, integer, sym = m.groups()
        assert sym.startswith(prefix), (sym, prefix, text)
        if num is not None:
            coeff = sp.Rational(int(num), int(den))
        elif integer is not None:
            coeff = sp.Integer(int(integer))
        else:
            coeff = sp.Integer(1)
        if sign == "-":
            coeff = -coeff
        i, j = sym.split("_")[1:]
        # building the sum in one go is dramatically faster than repeated
        # ``expr += ...`` (sympy re-canonicalises the Add on every step, which
        # made loading m_32x32.txt take ~7 minutes)
        terms.append(coeff * sp.Symbol(f"{prefix}_{int(i)}_{int(j)}"))
        pos = m.end()
    assert pos == len(text), (text, text[pos:])
    return sp.Add(*terms) if terms else sp.Integer(0)


def load_from_txt(m_path: str, c_path: str, name: str) -> Algorithm:
    """Load the ``m_*.txt`` / ``C_*.txt`` description pair."""
    alg = Algorithm(name=name, a_rows=0, a_cols=0, b_cols=0)

    with open(m_path) as f:
        for line in f:
            line = line.strip().rstrip(",").strip()
            if not line:
                continue
            lhs, rhs = line.split("=", 1)
            rhs = rhs.strip()
            # "<A form>)*(<B form>" -- split on the ") * (" boundary
            mm = re.match(r"^\((.*)\)\s*\*\s*\((.*)\)$", rhs, re.S)
            assert mm, line
            alg.a_forms.append(_parse_linear_form(mm.group(1), "A"))
            alg.b_forms.append(_parse_linear_form(mm.group(2), "B"))

    n_a = n_b = 0
    with open(c_path) as f:
        for line in f:
            line = line.strip().rstrip(",").strip()
            if not line:
                continue
            lhs, rhs = line.split("=", 1)
            lhs = lhs.strip()
            ci, cj = (int(t) for t in lhs.split("_")[1:])
            alg.c_terms[(ci, cj)] = []
            for m in re.finditer(r"([+-]?)(\d+/\d+|\d+)?\*?(m_\d+)", rhs):
                sign, num, mname = m.groups()
                k = int(mname.split("_")[1]) - 1
                coeff = sp.Rational(num) if num else sp.Integer(1)
                if sign == "-":
                    coeff = -coeff
                alg.c_terms[(ci, cj)].append((k, coeff))
            n_a = max(n_a, ci)
            n_b = max(n_b, cj)

    alg.a_rows, alg.b_cols = n_a, n_b
    alg.a_cols = _infer_inner_dim(alg)
    return alg


def _infer_inner_dim(alg: Algorithm) -> int:
    inner = 0
    for e in alg.a_forms + alg.b_forms:
        for s in e.free_symbols:
            i = int(str(s).split("_")[1])
            inner = max(inner, i)
    return inner


def load_from_triadset(path: str, name: str) -> Algorithm:
    """Load a Maple ``TriadSet`` of 4x4 Triads (as produced by fmm tools)."""
    src = open(path).read()
    m = re.search(r"TriadSet\(\[(.*)\]\)\s*:", src, re.S)
    assert m, "TriadSet(...) not found"
    body = m.group(1)

    triads = []
    for part in re.split(r"Triad\(", body):
        if not part.strip():
            continue
        mats = re.findall(r"Matrix\(\s*(\d+)\s*,\s*\d+\s*,\s*(\[\[.*?\]\])\s*\)", part, re.S)
        assert len(mats) == 3, part[:200]
        dims = {int(r) for r, _ in mats}
        assert len(dims) == 1, dims
        triads.append((int(dims.pop()), [sp.Matrix(sp.sympify(lit)) for _, lit in mats]))

    n = triads[0][0]
    assert all(d == n for d, _ in triads)

    alg = Algorithm(name=name, a_rows=n, a_cols=n, b_cols=n)
    for r, (_, (Ar, Br, Cr)) in enumerate(triads):
        af = sp.Integer(0)
        bf = sp.Integer(0)
        for i in range(n):
            for j in range(n):
                if Ar[i, j] != 0:
                    af += Ar[i, j] * sp.Symbol(f"A_{i+1}_{j+1}")
                if Br[i, j] != 0:
                    bf += Br[i, j] * sp.Symbol(f"B_{i+1}_{j+1}")
        alg.a_forms.append(sp.expand(af))
        alg.b_forms.append(sp.expand(bf))
        # C = sum_r <Ar,A><Br,B> Cr^T
        for i in range(n):
            for j in range(n):
                c = Cr[j, i]
                if c != 0:
                    alg.c_terms.setdefault((i + 1, j + 1), []).append((r, c))
    return alg


def load_algorithm(path: str, name: str = None) -> Algorithm:
    """Dispatch on file type."""
    name = name or path.rsplit("/", 1)[-1].rsplit(".", 1)[0]
    if path.endswith(".mpl"):
        return load_from_triadset(path, name)
    raise ValueError(f"cannot infer algorithm format from {path!r}")


def scale_denominators(exprs: Sequence[sp.Expr]) -> int:
    """Smallest positive integer s such that every s*expr has integer coefficients."""
    from math import gcd

    s = 1
    for e in exprs:
        syms = sorted(e.free_symbols, key=str)
        coeffs = sp.Poly(sp.expand(e), *syms).coeffs() if syms else [sp.expand(e)]
        for c in coeffs:
            d = sp.Rational(c).q
            s = s * d // gcd(s, d)
    return s


def _linear_form_str(expr: sp.Expr) -> str:
    """Render a linear form in the project's dense text style (A_1_1-A_2_3+...)."""
    out = []
    for term in sp.Add.make_args(sp.expand(expr)):
        coeff, sym = term.as_coeff_Mul()
        coeff = sp.Rational(coeff)
        name = str(sym)
        if not out:
            if coeff == 1:
                out.append(name)
            elif coeff == -1:
                out.append(f"-{name}")
            else:
                out.append(f"{sp.ccode(coeff)}*{name}")
        else:
            if coeff == 1:
                out.append(f"+{name}")
            elif coeff == -1:
                out.append(f"-{name}")
            elif coeff < 0:
                out.append(f"-{sp.ccode(-coeff)}*{name}")
            else:
                out.append(f"+{sp.ccode(coeff)}*{name}")
    return "".join(out)


def save_as_txt(alg: Algorithm, m_path: str, c_path: str) -> None:
    """Serialise back to the m_*/C_* text format (for inspection / diffing)."""
    with open(m_path, "w") as f:
        for k, (af, bf) in enumerate(zip(alg.a_forms, alg.b_forms), start=1):
            f.write(f"m_{k}=({_linear_form_str(af)})*({_linear_form_str(bf)}),\n")

    with open(c_path, "w") as f:
        for (i, j) in sorted(alg.c_terms):
            terms = sorted(alg.c_terms[(i, j)])
            parts = []
            for k, c in terms:
                c = sp.Rational(c)
                if c == 1:
                    parts.append(f"m_{k + 1}")
                elif c == -1:
                    parts.append(f"-m_{k + 1}")
                elif c < 0:
                    parts.append(f"-{sp.ccode(-c)}*m_{k + 1}")
                else:
                    parts.append(f"+{sp.ccode(c)}*m_{k + 1}")
            body = "".join(parts).lstrip("+")
            f.write(f"C_{i}_{j}={body},\n")
