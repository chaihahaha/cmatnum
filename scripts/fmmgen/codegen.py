"""Turn an :class:`~fmmgen.algorithm.Algorithm` into a recursive C routine.

The generator mirrors what the original per-algorithm scripts did, but for any
algorithm described by linear A/B forms:

1.  run CSE separately over the A-side and B-side forms so that shared
    linear combinations become scratch blocks;
2.  build one dependency graph containing every scratch block and every
    rank-one product;
3.  schedule that graph so the peak live scratch area is small (see
    :mod:`fmmgen.schedule`);
4.  emit a recursive ``fmm_<name>`` C function that falls back to ``dgemm``
    below a runtime-tunable block threshold.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from fractions import Fraction
from typing import Dict, List, Sequence, Tuple

import os
import pickle

import sympy as sp

from .algorithm import Algorithm
from .schedule import COMB, INPUT, PROD, Graph, assign_buffers, cse_expressions, peak_memory, schedule


@dataclass
class Options:
    name: str
    fn_name: str = None
    scheduler: str = "greedy"
    a_min_terms: int = 3
    b_min_terms: int = 3
    threshold_var: str = "fmm_base_block"
    #: directory used to cache the (expensive) sympy CSE results, or None
    cache_dir: str = "cache"

    def __post_init__(self):
        if self.fn_name is None:
            self.fn_name = f"fmm_{self.name}"


@dataclass
class Program:
    alg: Algorithm
    opts: Options
    graph: Graph = None
    order: List[str] = None
    slots: Dict[str, int] = None
    n_buffers: int = 0
    peak: Fraction = Fraction(0)
    lincomb: Dict[str, List[Tuple[str, sp.Expr]]] = field(default_factory=dict)
    shape_of: Dict[str, int] = field(default_factory=dict)
    operands: Dict[str, Tuple[sp.Expr, sp.Expr]] = field(default_factory=dict)

    # -- helpers -------------------------------------------------------- #
    def cname(self, node_name: str) -> str:
        """C identifier holding ``node_name`` (scratch slot / input / product)."""
        node = self.graph.nodes[node_name]
        if node.kind == COMB:
            return f"scratch[{self.slots[node_name]}]"
        if node.kind == PROD:
            return "m"
        return node_name

    def stats(self) -> Dict[str, int]:
        return {
            "n_inputs": sum(1 for n in self.graph.nodes.values() if n.kind == INPUT),
            "n_combs": sum(1 for n in self.graph.nodes.values() if n.kind == COMB),
            "n_prods": sum(1 for n in self.graph.nodes.values() if n.kind == PROD),
            "n_buffers": self.n_buffers,
            "peak_area_frac": self.peak,
        }


def _nice(coeff: sp.Expr) -> sp.Expr:
    """Normalise a coefficient without destroying exact rationals.

    ``sp.nsimplify`` is used to turn CSE-produced floats back into readable
    rationals, but applied to an *exact* rational it first converts to a float
    and then hunts for an algebraic closed form, e.g.
    ``nsimplify(Rational(3514958, 77847587))`` returns a product of 181st roots.
    Exact rationals are therefore passed through untouched.
    """
    if coeff.is_Rational:
        return coeff
    return sp.nsimplify(coeff, rational=True)


def _linear_terms(expr: sp.Expr) -> List[Tuple[str, sp.Expr]]:
    """Split a linear form into (symbol, coefficient) pairs."""
    terms = []
    for term in sp.Add.make_args(sp.expand(expr)):
        coeff, sym = term.as_coeff_Mul()
        terms.append((str(sym), _nice(coeff)))
    return terms


def _cse_cached(exprs, prefix: str, min_terms: int, cache_path):
    """Run the CSE, memoising the (potentially very expensive) result on disk."""
    if cache_path and os.path.isfile(cache_path):
        with open(cache_path, "rb") as f:
            return pickle.load(f)
    result = cse_expressions(exprs, prefix, min_terms)
    if cache_path:
        os.makedirs(os.path.dirname(cache_path), exist_ok=True)
        tmp = cache_path + ".tmp"
        with open(tmp, "wb") as f:
            pickle.dump(result, f)
        os.replace(tmp, cache_path)
    return result


def build_program(alg: Algorithm, opts: Options) -> Program:
    prog = Program(alg=alg, opts=opts)

    def cache(name):
        if not opts.cache_dir:
            return None
        return os.path.join(opts.cache_dir, f"cse_{opts.name}_{name}{opts.a_min_terms}{opts.b_min_terms}.pickle")

    a_repl, a_reduced = _cse_cached(alg.a_forms, f"{opts.name}_Ax", opts.a_min_terms, cache("A"))
    b_repl, b_reduced = _cse_cached(alg.b_forms, f"{opts.name}_Bx", opts.b_min_terms, cache("B"))

    # scratch area in units of N^2 (N = common matrix dimension)
    wa = Fraction(1, alg.a_rows) * Fraction(1, alg.a_cols)
    wb = Fraction(1, alg.a_cols) * Fraction(1, alg.b_cols)

    g = Graph()
    for i in range(alg.a_rows):
        for j in range(alg.a_cols):
            g.add(f"A_{i + 1}_{j + 1}", INPUT)
    for i in range(alg.a_cols):
        for j in range(alg.b_cols):
            g.add(f"B_{i + 1}_{j + 1}", INPUT)

    for sym, expr in a_repl:
        name = str(sym)
        terms = _linear_terms(expr)
        prog.lincomb[name] = terms
        prog.shape_of[name] = 0
        g.add(name, COMB, weight=wa, expr=expr, deps=[s for s, _ in terms], shape_key=0)
    for sym, expr in b_repl:
        name = str(sym)
        terms = _linear_terms(expr)
        prog.lincomb[name] = terms
        prog.shape_of[name] = 1
        g.add(name, COMB, weight=wb, expr=expr, deps=[s for s, _ in terms], shape_key=1)

    for k, (af, bf) in enumerate(zip(a_reduced, b_reduced)):
        pname = f"m{k + 1}"
        deps = sorted({s for s, _ in _linear_terms(af)} | {s for s, _ in _linear_terms(bf)})
        targets = [(i, j, c) for (i, j), terms in alg.c_terms.items() for (rk, c) in terms if rk == k]
        g.add(pname, PROD, deps=deps, rank=k, c_targets=targets)
        prog.operands[pname] = (af, bf)

    g.finalise()
    prog.graph = g
    prog.order = schedule(g, opts.scheduler, outputs={f"m{k + 1}" for k in range(alg.rank)})
    prog.slots, prog.n_buffers = assign_buffers(g, prog.order)
    prog.peak = peak_memory(g, prog.order)
    return prog


# ---------------------------------------------------------------------- #
# Emission
# ---------------------------------------------------------------------- #

def _ccnum(x) -> str:
    r = sp.Rational(x)
    if r.q == 1:
        return f"{int(r)}.0"
    return repr(float(r))


def _render_lincomb(dst: str, terms: Sequence[Tuple[str, sp.Expr]], resolve) -> str:
    srcs = ", ".join(resolve(s) for s, _ in terms)
    coeffs = ", ".join(_ccnum(c) for _, c in terms)
    return (f"    matlincomb_double_init({dst}, {len(terms)}, "
            f"(double_cmat[]){{{srcs}}}, (double[]){{{coeffs}}});")


def emit(prog: Program) -> Tuple[str, str]:
    """Return the (header, source) text for a compiled program."""
    alg, opts = prog.alg, prog.opts
    R, K, S = alg.a_rows, alg.a_cols, alg.b_cols
    guard = f"FMM_{opts.name.upper()}_H"

    header = f"""\
#ifndef {guard}
#define {guard}

#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long {opts.fn_name}_fast_calls;
extern unsigned long {opts.fn_name}_blas_calls;

int {opts.fn_name}(double_cmat C, double_cmat A, double_cmat B);

#endif
"""

    body: List[str] = []
    w = body.append

    w("    shape_uint M = A.shape[0];")
    w("    shape_uint Kd = A.shape[1];")
    w("    shape_uint Nd = B.shape[1];")
    w("    if (B.shape[0] != Kd || C.shape[0] != M || C.shape[1] != Nd ||")
    w(f"        !(M % {R} == 0 && Kd % {K} == 0 && Nd % {S} == 0) ||")
    w(f"        M <= (shape_uint){opts.threshold_var}) {{")
    w(f"        {opts.fn_name}_blas_calls++;")
    w("        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,")
    w("                    C.shape[0], C.shape[1], A.shape[1],")
    w("                    1.0, A.data[0], A.arena_shape[1],")
    w("                    B.data[0], B.arena_shape[1],")
    w("                    0.0, C.data[0], C.arena_shape[1]);")
    w("        return 0;")
    w("    }")
    w(f"    {opts.fn_name}_fast_calls++;")
    w(f"    const shape_uint BLHA = M / {R}, BLWA = Kd / {K}, BLHB = Kd / {K}, BLWB = Nd / {S};")
    w(f"    const shape_uint BLHC = M / {R}, BLWC = Nd / {S};")
    w("    const shape_uint NA = BLHA * BLWA, NB = BLHB * BLWB, NC = BLHC * BLWC;")
    w("    (void)NA; (void)NB; (void)NC;")
    w("")

    # one scratch array per distinct buffer slot, created once
    slot_shape: Dict[int, int] = {}
    for name in prog.order:
        if prog.graph.nodes[name].kind == COMB:
            slot_shape.setdefault(prog.slots[name], prog.shape_of[name])
    w("    /*--- scratch blocks -------------------------------------------*/")
    w(f"    double_cmat scratch[{max(prog.n_buffers, 1)}];")
    for slot in sorted(slot_shape):
        dims = "pairuint {BLHA, BLWA}" if slot_shape[slot] == 0 else "pairuint {BLHB, BLWB}"
        w(f"    create_double_matrix({dims}, &scratch[{slot}]);")
    for slot in range(prog.n_buffers):
        if slot not in slot_shape:
            w(f"    scratch[{slot}].arena = NULL; scratch[{slot}].data = NULL;")
    w("")

    w("    double_cmat tmpA, tmpB, m;")
    w("    create_double_matrix(pairuint {BLHA, BLWA}, &tmpA);")
    w("    create_double_matrix(pairuint {BLHB, BLWB}, &tmpB);")
    w("    create_double_matrix(pairuint {BLHC, BLWC}, &m);")
    w("")

    w("    /*--- macro-block views ----------------------------------------*/")
    for j in range(K):
        w(f"    double_cmat A_x_{j + 1};")
    for j in range(S):
        w(f"    double_cmat B_x_{j + 1};")
        w(f"    double_cmat C_x_{j + 1};")
    for j in range(K):
        w(f"    create_slice_double_matrix_contiguous(&A_x_{j + 1}, A, pairint {{0, M}}, pairint {{{j} * BLWA, {j + 1} * BLWA}});")
    for j in range(S):
        w(f"    create_slice_double_matrix_contiguous(&B_x_{j + 1}, B, pairint {{0, Kd}}, pairint {{{j} * BLWB, {j + 1} * BLWB}});")
        w(f"    create_double_matrix(pairuint {{M, BLWC}}, &C_x_{j + 1});")
    for i in range(R):
        for j in range(K):
            w(f"    double_cmat A_{i + 1}_{j + 1} = slice_double_matrix(A_x_{j + 1}, pairint {{{i} * BLHA, {i + 1} * BLHA}}, pairint {{0, BLWA}});")
    for i in range(K):
        for j in range(S):
            w(f"    double_cmat B_{i + 1}_{j + 1} = slice_double_matrix(B_x_{j + 1}, pairint {{{i} * BLHB, {i + 1} * BLHB}}, pairint {{0, BLWB}});")
            w(f"    double_cmat C_{i + 1}_{j + 1} = slice_double_matrix(C_x_{j + 1}, pairint {{{i} * BLHC, {i + 1} * BLHC}}, pairint {{0, BLWC}});")
    w("")

    w("    /*--- scheduled evaluation -------------------------------------*/")
    for name in prog.order:
        node = prog.graph.nodes[name]
        if node.kind == COMB:
            w(_render_lincomb(f"scratch[{prog.slots[name]}]", prog.lincomb[name], prog.cname))
        elif node.kind == PROD:
            af, bf = prog.operands[name]
            a_terms, b_terms = _linear_terms(af), _linear_terms(bf)
            # If an operand is a single block scaled by a constant, hand the
            # block straight to the recursive call and fold the constant into
            # the C coefficients -- this removes a whole scratch pass.
            scale = sp.Integer(1)
            a_arg, b_arg = "tmpA", "tmpB"
            if len(a_terms) == 1:
                a_arg = prog.cname(a_terms[0][0])
                scale *= a_terms[0][1]
            else:
                w(_render_lincomb("tmpA", a_terms, prog.cname))
            if len(b_terms) == 1:
                b_arg = prog.cname(b_terms[0][0])
                scale *= b_terms[0][1]
            else:
                w(_render_lincomb("tmpB", b_terms, prog.cname))
            w(f"    {opts.fn_name}(m, {a_arg}, {b_arg});")
            for (i, j, coeff) in node.c_targets:
                w(f"    cblas_daxpy(NC, {_ccnum(_nice(coeff * scale))}, m.data[0], 1, C_{i}_{j}.data[0], 1);")
    w("")

    w("    /*--- write back ------------------------------------------------*/")
    for j in range(S):
        w(f"    assign_double_slice(C, C_x_{j + 1}, pairint {{0, M}}, pairint {{{j} * BLWC, {j + 1} * BLWC}});")
    w("")
    for j in range(K):
        w(f"    free_double_matrix(A_x_{j + 1});")
    for j in range(S):
        w(f"    free_double_matrix(B_x_{j + 1});")
        w(f"    free_double_matrix(C_x_{j + 1});")
    for slot in sorted(slot_shape):
        w(f"    free_double_matrix(scratch[{slot}]);")
    w("    free_double_matrix(tmpA);")
    w("    free_double_matrix(tmpB);")
    w("    free_double_matrix(m);")
    w("    return 0;")
    w("}")

    source = (f'#include "cmat.h"\n#include "fmm_{opts.name}.h"\n\n'
              f"unsigned long {opts.fn_name}_fast_calls = 0;\n"
              f"unsigned long {opts.fn_name}_blas_calls = 0;\n\n"
              f"int {opts.fn_name}(double_cmat C, double_cmat A, double_cmat B) {{\n"
              + "\n".join(body) + "\n")
    return header, source
