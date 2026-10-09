"""Common-subexpression extraction and evaluation-order scheduling.

The generated C routine computes a large number of *linear combinations* of
macro-blocks (the CSE temporaries) followed by rank-many recursive matrix
products that are immediately accumulated into C.  Each CSE temporary occupies
a scratch block for the interval between the point it is produced and its last
use, so the peak number of simultaneously live temporaries -- weighted by block
area -- directly determines the scratch memory of one recursion level, which is
the dominant memory cost at large ``N``.

Choosing the evaluation order that minimises that peak is a DAG scheduling
problem (NP-hard in general); this module provides the original heuristic, an
area-aware greedy scheduler, and a depth-first variant, plus buffer pooling.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from fractions import Fraction
from itertools import count
from typing import Dict, List, Sequence, Set, Tuple

import sympy as sp


INPUT = "input"
COMB = "comb"       # linear combination of other blocks -> needs a buffer
PROD = "prod"       # recursive matrix product -> shares one recycled buffer


@dataclass
class Node:
    name: str
    kind: str
    #: scratch area in units of N^2 (only meaningful for COMB nodes)
    weight: Fraction = Fraction(0)
    #: distinct block shapes never share a buffer
    shape_key: int = 0
    expr: sp.Expr = None
    deps: List[str] = field(default_factory=list)
    consumers: List[str] = field(default_factory=list)
    #: number of not-yet-scheduled consumers
    remaining: int = 0
    #: rank index for PROD nodes
    rank: int = -1
    #: C blocks this product feeds: (row block, col block, coefficient)
    c_targets: List[Tuple[int, int, sp.Expr]] = field(default_factory=list)


class Graph:
    """A small expression DAG with string-keyed adjacency."""

    def __init__(self) -> None:
        self.nodes: Dict[str, Node] = {}
        self.inputs: Set[str] = set()

    def add(self, name, kind, weight=Fraction(0), expr=None, deps=(), rank=-1,
            c_targets=None, shape_key=0) -> Node:
        node = self.nodes.get(name)
        if node is None:
            node = Node(name=name, kind=kind)
            self.nodes[name] = node
        node.kind = kind
        node.weight = Fraction(weight)
        node.shape_key = shape_key
        node.expr = expr
        node.deps = list(deps)
        node.rank = rank
        node.c_targets = list(c_targets or [])
        return node

    def finalise(self) -> None:
        for n in self.nodes.values():
            n.consumers = []
        for n in self.nodes.values():
            for d in n.deps:
                self.nodes[d].consumers.append(n.name)
        for n in self.nodes.values():
            n.remaining = len(n.consumers)
        for n in self.nodes.values():
            if n.kind == INPUT:
                self.inputs.add(n.name)

    def combs(self) -> List[str]:
        return [n for n, node in self.nodes.items() if node.kind == COMB]

    def prods(self) -> List[str]:
        return [n for n, node in self.nodes.items() if node.kind == PROD]


# ---------------------------------------------------------------------- #
# CSE
# ---------------------------------------------------------------------- #

def limit_cse(replacements, reduced_exprs, min_terms: int, by_inputs: bool = True):
    """Inline CSE temporaries that depend on fewer than ``min_terms`` leaves.

    A temporary is only worth a scratch buffer if the expression it names
    combines at least ``min_terms`` *distinct leaf inputs* (``by_inputs``), or
    -- the historical rule -- at least ``min_terms`` immediate operands.

    Two things are done differently from the original implementation:

    * the discarded temporaries are inlined in a single forward pass over the
      (topologically ordered) replacement list, using the already-resolved
      expression of every dependency.  The original substituted each discarded
      symbol into *every* kept replacement, which is quadratic and -- because
      it ran in forward order -- could re-introduce symbols that had already
      been discarded;
    * "worth keeping" is decided on the number of distinct leaves the
      expression expands to, not on the number of immediate operands.
    """
    repl = list(replacements)
    n = len(repl)
    sym_index = {s if isinstance(s, sp.Symbol) else sp.Symbol(str(s)): i for i, (s, _) in enumerate(repl)}

    leaves: List[set] = []
    for i, (_, expr) in enumerate(repl):
        acc = set()
        for f in expr.free_symbols:
            j = sym_index.get(f)
            if j is None or j >= i:
                acc.add(f)
            else:
                acc |= leaves[j]
        leaves.append(acc)

    if by_inputs:
        keep_set = {i for i in range(n) if len(leaves[i]) >= min_terms}
    else:
        keep_set = {i for i in range(n) if len(repl[i][1].free_symbols) >= min_terms}

    #: fully expanded form of every *discarded* replacement, expressed in leaves
    #: and kept temps only
    resolved: Dict[int, sp.Expr] = {}
    out = []
    for i, (sym, expr) in enumerate(repl):
        mapping = {}
        for f in expr.free_symbols:
            j = sym_index.get(f)
            if j is not None and j < i and j not in keep_set:
                mapping[f] = resolved[j]
        expanded = expr.subs(mapping) if mapping else expr
        if i in keep_set:
            out.append((sym, expanded))
        else:
            resolved[i] = expanded

    if resolved:
        mapping = {}
        for expr in reduced_exprs:
            for f in expr.free_symbols:
                j = sym_index.get(f)
                if j is not None and j not in keep_set:
                    mapping[f] = resolved[j]
        if mapping:
            reduced_exprs = [expr.subs(mapping) for expr in reduced_exprs]

    return out, list(reduced_exprs)


def cse_expressions(expr_list: Sequence[sp.Expr], prefix: str, min_terms: int, by_inputs: bool = True):
    """SymPy CSE with the project's inlining rule."""
    replacements, reduced = sp.cse(expr_list, symbols=(sp.Symbol(f"{prefix}{i}") for i in count()),
                                   optimizations="basic")
    return limit_cse(replacements, reduced, min_terms, by_inputs=by_inputs)


# ---------------------------------------------------------------------- #
# Scheduling
# ---------------------------------------------------------------------- #

def _weighted_peak(graph: Graph, order: Sequence[str]) -> Fraction:
    """Peak live scratch area along ``order``.

    A source block is read *during* the computation of its consumer, so it is
    still resident at the instant the consumer's own block appears.  The peak
    therefore has to be sampled before the dying operands are released.
    """
    remaining = {n: len(node.consumers) for n, node in graph.nodes.items()}
    live: Dict[str, Fraction] = {}
    peak = Fraction(0)
    total = Fraction(0)
    for name in order:
        node = graph.nodes[name]
        if node.kind == COMB:
            peak = max(peak, total + node.weight)
            live[name] = node.weight
            total += node.weight
        for d in node.deps:
            remaining[d] -= 1
            if remaining[d] == 0 and d in live:
                total -= live.pop(d)
    return peak


def _legacy_order(graph: Graph, outputs: Set[str], prescheduled: Sequence[str] = ()) -> List[str]:
    """Greedy in the original priority order, without networkx.

    Priority is ``(is_output, index_of_last_use, out_degree)`` descending, which
    is what ``compute_optimized_order()`` used in the original generators.
    ``prescheduled`` nodes are emitted first and treated as already available.
    """
    pre = list(prescheduled)
    pre_set = set(pre)

    indeg = {n: sum(1 for d in node.deps if d not in pre_set) for n, node in graph.nodes.items()}
    # Kalman/Kahn topological order (used only for index_of_last_use)
    ready = [n for n in graph.nodes if n not in pre_set and indeg[n] == 0]
    topo: List[str] = []
    while ready:
        ready.sort()
        cur = ready.pop(0)
        topo.append(cur)
        for c in graph.nodes[cur].consumers:
            if c in pre_set:
                continue
            indeg[c] -= 1
            if indeg[c] == 0:
                ready.append(c)

    index_of_last_use = {n: 0 for n in graph.nodes}
    for i, n in enumerate(topo):
        for d in graph.nodes[n].deps:
            if d not in pre_set:
                index_of_last_use[d] = i

    is_output = {n: n in outputs for n in graph.nodes}
    indeg = {n: sum(1 for d in node.deps if d not in pre_set) for n, node in graph.nodes.items()}
    ready = [n for n in graph.nodes if n not in pre_set and indeg[n] == 0]
    order: List[str] = list(pre)
    while ready:
        ready.sort(key=lambda n: (is_output[n], index_of_last_use[n],
                                  len(graph.nodes[n].consumers)), reverse=True)
        cur = ready.pop(0)
        order.append(cur)
        for c in graph.nodes[cur].consumers:
            if c in pre_set:
                continue
            indeg[c] -= 1
            if indeg[c] == 0:
                ready.append(c)
    return order


def schedule_legacy(graph: Graph, outputs: Set[str]) -> List[str]:
    """The original heuristic: greedy on (is_output, last-use index, out-degree)."""
    return _legacy_order(graph, outputs)


def schedule_legacy_split(graph: Graph, outputs: Set[str]) -> List[str]:
    """Reproduce the original generators' order.

    The historical 3x3x6/32x32 generators emitted *every* B-side linear
    combination first and kept all of them alive until the routine returned,
    then walked the A-side dependency graph interleaved with the products.
    That is what this scheduler models, so it is the honest baseline for
    measuring how much the joint scheduler improves peak scratch memory.
    """
    pre = [n for n, node in graph.nodes.items() if node.kind == COMB and node.shape_key == 1]
    return _legacy_order(graph, outputs, prescheduled=pre)


def _greedy(graph: Graph, rng=None, tie_mode: str = "prod") -> List[str]:
    """Area-aware greedy list scheduling.

    At every step we consider all ready nodes and pick the one that leaves the
    smallest live scratch area.  Scheduling a COMB adds its block area,
    scheduling a PROD frees every operand for which it was the last consumer.

    The primary key (resulting live area) is often tied, so ``tie_mode``
    chooses the secondary key:

    ``prod``
        prefer products, then the node that kills the most operands (default);
    ``unlock``
        prefer the node that makes the most of its own consumers ready, which
        keeps the schedule close to a depth-first traversal;
    ``soon``
        prefer the node with the fewest remaining consumers.
    """
    remaining = {n: len(node.consumers) for n, node in graph.nodes.items()}
    indeg = {n: len(node.deps) for n, node in graph.nodes.items()}
    remaining_indeg = dict(indeg)
    ready: List[str] = [n for n, d in indeg.items() if d == 0]
    live: Dict[str, Fraction] = {}
    total = Fraction(0)
    order: List[str] = []

    def score(name: str):
        node = graph.nodes[name]
        freed = Fraction(0)
        deaths = 0
        for d in node.deps:
            if remaining[d] == 1:
                freed += live.get(d, Fraction(0))
                deaths += 1
        # a COMB adds its block while its operands are still resident
        add = node.weight if node.kind == COMB else Fraction(0)
        pressure = total + add
        jitter = (rng.random() * 1e-6) if rng is not None else 0.0

        if tie_mode == "unlock":
            unlock = sum(1 for c in node.consumers if remaining_indeg[c] == 1)
            return (float(pressure) + jitter, -unlock, 0 if node.kind == PROD else 1, -deaths)
        if tie_mode == "soon":
            return (float(pressure) + jitter, len(node.consumers),
                    0 if node.kind == PROD else 1, -deaths)
        return (float(pressure) + jitter, 0 if node.kind == PROD else 1, -deaths, -float(freed))

    while ready:
        best = min(ready, key=score)
        ready.remove(best)
        order.append(best)
        node = graph.nodes[best]
        for d in node.deps:
            remaining[d] -= 1
            if remaining[d] == 0 and d in live:
                total -= live.pop(d)
        if node.kind == COMB:
            live[best] = node.weight
            total += node.weight
        for succ in node.consumers:
            remaining_indeg[succ] -= 1
            indeg[succ] -= 1
            if indeg[succ] == 0:
                ready.append(succ)
    return order


def schedule_greedy(graph: Graph) -> List[str]:
    return _greedy(graph)


def schedule_dfs(graph: Graph) -> List[str]:
    """Depth-first (post-order) evaluation from the product nodes."""
    order: List[str] = []
    seen: Set[str] = set()
    for root in graph.prods():
        stack = [(root, False)]
        while stack:
            name, expanded = stack.pop()
            if name in seen:
                continue
            node = graph.nodes[name]
            if expanded or not node.deps:
                seen.add(name)
                order.append(name)
                continue
            stack.append((name, True))
            for d in reversed(node.deps):
                if d not in seen:
                    stack.append((d, False))
    for name in graph.nodes:
        if name not in seen and graph.nodes[name].kind != INPUT:
            order.append(name)
    return order


def schedule_restarts(graph: Graph, restarts: int = 16, seed: int = 0) -> List[str]:
    """Randomised restarts of the greedy scheduler; keeps the best schedule."""
    import random

    rng = random.Random(seed)
    best_order = _greedy(graph)
    best_peak = _weighted_peak(graph, best_order)
    for _ in range(restarts):
        order = _greedy(graph, rng)
        peak = _weighted_peak(graph, order)
        if peak < best_peak:
            best_peak, best_order = peak, order
    return best_order


def schedule_best(graph: Graph, outputs: Set[str] = frozenset(),
                  restarts: int = 24, seed: int = 0) -> List[str]:
    """Portfolio scheduler: run every heuristic and keep the lowest peak.

    No single list-scheduling rule dominates (the ``legacy`` priority beats the
    live-area greedy on some graphs and loses badly on others), so the cheapest
    robust thing is to evaluate all of them and keep the best.  The randomised
    restarts then explore the plateau of equally-scored greedy choices.
    """
    import random

    candidates = [
        schedule_legacy(graph, set(outputs)),
        schedule_legacy_split(graph, set(outputs)),
        schedule_greedy(graph),
        schedule_dfs(graph),
        _greedy(graph, tie_mode="unlock"),
        _greedy(graph, tie_mode="soon"),
    ]
    best = min(candidates, key=lambda o: _weighted_peak(graph, o))
    best_peak = _weighted_peak(graph, best)

    rng = random.Random(seed)
    for _ in range(restarts):
        mode = ("prod", "unlock", "soon")[_ % 3]
        order = _greedy(graph, rng, tie_mode=mode)
        peak = _weighted_peak(graph, order)
        if peak < best_peak:
            best_peak, best = peak, order
    return best


SCHEDULERS = {
    "legacy": schedule_legacy,
    "legacy_split": schedule_legacy_split,
    "greedy": schedule_greedy,
    "dfs": schedule_dfs,
    "restarts": schedule_restarts,
    "best": schedule_best,
}


def schedule(graph: Graph, strategy: str = "best", outputs: Set[str] = frozenset()) -> List[str]:
    fn = SCHEDULERS.get(strategy)
    if fn is None:
        raise ValueError(f"unknown scheduler {strategy!r}")
    if strategy in ("legacy", "legacy_split", "best"):
        return fn(graph, set(outputs))
    return fn(graph)


# ---------------------------------------------------------------------- #
# Buffer allocation
# ---------------------------------------------------------------------- #

def assign_buffers(graph: Graph, order: Sequence[str]) -> Tuple[Dict[str, int], int]:
    """Map every COMB node to a scratch slot (pooled per block shape).

    Returns ``(slot_of_node, n_buffers)``.

    A node must not write its result into the buffer of one of its own
    operands: the operand is still being read while the result is produced.
    Slots belonging to operands that die at this node are therefore only
    returned to the pool *after* the destination has been chosen.
    """
    remaining = {n: len(node.consumers) for n, node in graph.nodes.items()}
    pools: Dict[object, List[int]] = {}
    assigned: Dict[str, int] = {}
    live: Dict[str, int] = {}
    used = 0
    for name in order:
        node = graph.nodes[name]
        dying = [d for d in node.deps if remaining[d] == 1 and d in live]
        for d in node.deps:
            remaining[d] -= 1
        if node.kind == COMB:
            pool = pools.setdefault(node.shape_key, [])
            forbidden = {live[d] for d in dying}
            s = None
            for idx, cand in enumerate(pool):
                if cand not in forbidden:
                    s = pool.pop(idx)
                    break
            if s is None:
                s = used
                used += 1
            live[name] = s
            assigned[name] = s
        for d in dying:
            pools.setdefault(graph.nodes[d].shape_key, []).append(live.pop(d))
    return assigned, used


def peak_memory(graph: Graph, order: Sequence[str]) -> Fraction:
    return _weighted_peak(graph, order)
