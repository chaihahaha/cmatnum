#!/usr/bin/env python3
"""Render the benchmark CSVs into charts under ./imgs."""

from __future__ import annotations

import csv
import os

os.environ.setdefault("MPLCONFIGDIR", os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "cache"))
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt  # noqa: E402
import numpy as np  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RESULTS = os.path.join(ROOT, "results")
IMGS = os.path.join(ROOT, "imgs")

ALG_COLOR = {"3x3": "tab:blue", "3x3x6": "tab:orange", "4x4": "tab:green", "32x32": "tab:red"}


def read(name):
    path = os.path.join(RESULTS, name)
    if not os.path.isfile(path):
        return []
    with open(path) as f:
        return list(csv.DictReader(f))


def f(row, key):
    try:
        return float(row[key])
    except (KeyError, ValueError):
        return float("nan")


def plot_size_sweep():
    rows = read("size_sweep.csv")
    if not rows:
        return
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 4.5))
    for alg in dict.fromkeys(r["alg"] for r in rows):
        alg_rows = [r for r in rows if r["alg"] == alg and r["alg"] != "blas"]
        if alg_rows:
            n = [int(r["M"]) for r in alg_rows]
            g = [f(r, "gflops") for r in alg_rows]
            ax1.plot(n, g, "o-", color=ALG_COLOR.get(alg), label=f"fmm_{alg}")
        b_rows = [r for r in rows if r["alg"] == "blas" and int(r["M"]) in
                  [int(x["M"]) for x in alg_rows]]
        if alg_rows and b_rows:
            nb = [int(r["M"]) for r in b_rows]
            gb = [f(r, "gflops") for r in b_rows]
            ax1.plot(nb, gb, "s--", color=ALG_COLOR.get(alg), alpha=0.45,
                     label=f"BLAS ({alg} shape)")

    ax1.set_xscale("log", base=2)
    ax1.set_xlabel("N (M = K)")
    ax1.set_ylabel("GFLOP/s (2N³/t)")
    ax1.set_title("fast algorithms vs BLAS")
    ax1.grid(alpha=0.3)
    ax1.legend(fontsize=8)

    rows = read("scaling.csv")
    for alg in dict.fromkeys(r["alg"] for r in rows):
        alg_rows = [r for r in rows if r["alg"] == alg]
        n = np.array([int(r["M"]) for r in alg_rows], dtype=float)
        t = np.array([f(r, "seconds") for r in alg_rows])
        if len(n) >= 2:
            # last segment = closest to the asymptotic regime
            slope = (np.log(t[-1]) - np.log(t[-2])) / (np.log(n[-1]) - np.log(n[-2]))
            ax2.loglog(n, t, "o-", color=ALG_COLOR.get(alg),
                       label=f"{alg}: measured {slope:.3f}")
    ax2.set_xlabel("N (M = K) at fixed base-case block size")
    ax2.set_ylabel("seconds")
    ax2.set_title("measured scaling, last-segment slope "
                  "(theory: 3x3 2.727, 3x3x6 2.727, 4x4 2.792)")
    ax2.grid(alpha=0.3, which="both")
    ax2.legend(fontsize=8)
    fig.tight_layout()
    out = os.path.join(IMGS, "size_sweep.png")
    fig.savefig(out, dpi=130)
    print("wrote", out)


def plot_base_sweep():
    rows = read("base_sweep.csv")
    if not rows:
        return
    base = [int(r["base"]) for r in rows]
    t = [f(r, "seconds") for r in rows]
    g = [f(r, "gflops") for r in rows]
    fig, ax = plt.subplots(figsize=(6.5, 4.2))
    ax.plot(base, t, "o-", color="tab:green")
    ax.set_xscale("log", base=2)
    ax.set_xlabel("fmm_base_block")
    ax.set_ylabel("seconds")
    ax.set_title("4x4 @ N=8192: base-case threshold sweep")
    ax.grid(alpha=0.3)
    for x, y, gg in zip(base, t, g):
        ax.annotate(f"{gg:.0f} GF/s", (x, y), textcoords="offset points",
                    xytext=(0, 8), ha="center", fontsize=7)
    out = os.path.join(IMGS, "base_sweep.png")
    fig.tight_layout()
    fig.savefig(out, dpi=130)
    print("wrote", out)


def main() -> int:
    os.makedirs(IMGS, exist_ok=True)
    plot_size_sweep()
    plot_base_sweep()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
