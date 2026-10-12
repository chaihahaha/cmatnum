#!/usr/bin/env python3
"""Generate recursive C implementations of fast matrix-multiplication algorithms.

Examples
--------
    python3 scripts/generate_fmm.py --list
    python3 scripts/generate_fmm.py 4x4
    python3 scripts/generate_fmm.py 3x3x6 --scheduler greedy --info
    python3 scripts/generate_fmm.py 4x4 --emit-txt algorithms
    python3 scripts/generate_fmm.py --compare-schedulers 4x4 3x3x6
"""

from __future__ import annotations

import argparse
import os
import sys
import time
from typing import Callable, Dict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from fmmgen import Options, build_program, emit, load_from_triadset, load_from_txt, save_as_txt

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ALG_DIR = os.path.join(ROOT, "algorithms")
SRC_DIR = os.path.join(ROOT, "src")
ASSET_DIR = os.path.join(ROOT, "assets")

#: algorithm registry: name -> (description, loader, default options)
ALGORITHMS: Dict[str, Callable[[], object]] = {
    "3x3": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_3x3.txt"), os.path.join(ALG_DIR, "C_3x3.txt"), "3x3"),
    "3x3x6": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_3x3x6.txt"), os.path.join(ALG_DIR, "C_3x3x6.txt"), "3x3x6"),
    "4x4": lambda: load_from_triadset(
        os.path.join(ASSET_DIR, "4x4x4_tensor.mpl"), "4x4"),
    # rank-reduced *approximate* 4x4x4 algorithms (Smirnov-style border-rank
    # search, see scripts/approx4x4/ and docs/approx_4x4.md)
    "4x4r46": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_4x4r46.txt"), os.path.join(ALG_DIR, "C_4x4r46.txt"), "4x4r46"),
    "4x4r47": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_4x4r47.txt"), os.path.join(ALG_DIR, "C_4x4r47.txt"), "4x4r47"),
    "4x4r43": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_4x4r43.txt"), os.path.join(ALG_DIR, "C_4x4r43.txt"), "4x4r43"),
    "32x32": lambda: load_from_txt(
        os.path.join(ALG_DIR, "m_32x32.txt"), os.path.join(ALG_DIR, "C_32x32.txt"), "32x32"),
}

#: per-algorithm defaults for CSE inlining
MIN_TERMS = {"3x3": (2, 2), "3x3x6": (3, 2), "4x4": (3, 3), "32x32": (3, 3),
             "4x4r46": (3, 3), "4x4r47": (3, 3), "4x4r43": (3, 3)}


#: source files whose modification invalidates the parsed-algorithm cache
ALGORITHM_SOURCES = {
    "3x3": ["algorithms/m_3x3.txt", "algorithms/C_3x3.txt"],
    "3x3x6": ["algorithms/m_3x3x6.txt", "algorithms/C_3x3x6.txt"],
    "4x4": ["assets/4x4x4_tensor.mpl"],
    "4x4r46": ["algorithms/m_4x4r46.txt", "algorithms/C_4x4r46.txt"],
    "4x4r47": ["algorithms/m_4x4r47.txt", "algorithms/C_4x4r47.txt"],
    "4x4r43": ["algorithms/m_4x4r43.txt", "algorithms/C_4x4r43.txt"],
    "32x32": ["algorithms/m_32x32.txt", "algorithms/C_32x32.txt"],
}


def load(name: str):
    """Load an algorithm description, caching the (sometimes slow) parse."""
    if name not in ALGORITHMS:
        raise SystemExit(f"unknown algorithm {name!r}; known: {', '.join(ALGORITHMS)}")
    import pickle

    cache_path = os.path.join(ROOT, "cache", f"alg_{name}.pickle")
    sources = [os.path.join(ROOT, p) for p in ALGORITHM_SOURCES.get(name, [])]
    newest = max((os.path.getmtime(p) for p in sources if os.path.exists(p)), default=0.0)
    if os.path.isfile(cache_path) and os.path.getmtime(cache_path) >= newest:
        with open(cache_path, "rb") as f:
            return pickle.load(f)
    alg = ALGORITHMS[name]()
    os.makedirs(os.path.dirname(cache_path), exist_ok=True)
    tmp = cache_path + ".tmp"
    with open(tmp, "wb") as f:
        pickle.dump(alg, f)
    os.replace(tmp, cache_path)
    return alg


def write_source(path: str, text: str) -> None:
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + ".tmp"
    with open(tmp, "w") as f:
        f.write(text)
    os.replace(tmp, path)


def generate(name: str, scheduler: str, outdir: str, info: bool = False) -> None:
    t0 = time.time()
    alg = load(name)
    a_min, b_min = MIN_TERMS.get(name, (3, 3))
    opts = Options(name=name, scheduler=scheduler, a_min_terms=a_min, b_min_terms=b_min)
    prog = build_program(alg, opts)
    stats = prog.stats()
    print(f"[{name}] rank={alg.rank} blocks={alg.a_rows}x{alg.a_cols}x{alg.b_cols} "
          f"combs={stats['n_combs']} prods={stats['n_prods']} "
          f"buffers={stats['n_buffers']} peak_area={float(stats['peak_area_frac']):.6g}N^2 "
          f"({time.time() - t0:.1f}s)")
    if info:
        return
    header, source = emit(prog)
    write_source(os.path.join(outdir, f"fmm_{name}.h"), header)
    write_source(os.path.join(outdir, f"fmm_{name}.c"), source)
    print(f"[{name}] wrote {os.path.join(outdir, f'fmm_{name}.c')} "
          f"({len(source) / 1024:.0f} KiB)")


def emit_txt(name: str, outdir: str) -> None:
    alg = load(name)
    os.makedirs(outdir, exist_ok=True)
    save_as_txt(alg, os.path.join(outdir, f"m_{name}.txt"), os.path.join(outdir, f"C_{name}.txt"))
    print(f"[{name}] wrote algorithm description to {outdir}")


def compare_schedulers(names, outdir: str) -> None:
    rows = []
    for name in names:
        alg = load(name)
        a_min, b_min = MIN_TERMS.get(name, (3, 3))
        for sched in ("legacy_split", "legacy", "greedy", "dfs", "restarts", "best"):
            opts = Options(name=name, scheduler=sched, a_min_terms=a_min, b_min_terms=b_min)
            t0 = time.time()
            prog = build_program(alg, opts)
            rows.append((name, sched, prog.n_buffers, float(prog.peak), time.time() - t0))
    print(f"{'algorithm':10} {'scheduler':10} {'buffers':>8} {'peak area (N^2)':>16} {'secs':>7}")
    for name, sched, nb, peak, dt in rows:
        print(f"{name:10} {sched:10} {nb:8d} {peak:16.6g} {dt:7.2f}")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("algorithms", nargs="*", help="algorithm names to generate")
    ap.add_argument("--list", action="store_true", help="list known algorithms")
    ap.add_argument("--scheduler", default="best", choices=["best", "legacy", "legacy_split", "greedy", "dfs", "restarts"])
    ap.add_argument("--outdir", default=SRC_DIR, help="where to write the C files")
    ap.add_argument("--info", action="store_true", help="only print statistics, do not write C")
    ap.add_argument("--emit-txt", metavar="DIR", help="write the m_/C_ algorithm description")
    ap.add_argument("--compare-schedulers", action="store_true")
    args = ap.parse_args()

    if args.list:
        for name in ALGORITHMS:
            print(name)
        return 0

    names = args.algorithms
    if not names:
        ap.error("no algorithm given (use --list to see them)")

    if args.compare_schedulers:
        compare_schedulers(names, args.outdir)
        return 0

    for name in names:
        if args.emit_txt:
            emit_txt(name, args.emit_txt)
        generate(name, args.scheduler, args.outdir, info=args.info)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
