# Rank-reduced approximate 4x4x4 algorithms (Smirnov's method)

Goal: apply the border-rank search method of

> A. V. Smirnov, *The bilinear complexity and practical algorithms for matrix
> multiplication*, Comput. Math. Math. Phys. **53** (2013) 1781–1795
> (`assets/smirnov_approx_matmul.pdf`)

to the 4x4x4 matrix-multiplication tensor, to obtain a **rank-R approximate**
algorithm that is cheaper than the exact rank-48 kernel shipped in
`assets/4x4x4_tensor.mpl`, and whose *measured* matrix-multiplication relative
error stays inside a prescribed budget.

## 1. The method, as implemented

Smirnov's approach (eqs. (1)–(5) of the paper):

1. Write the algorithm as `C = Σ_{r=1..R} <a_r,A><b_r,B> c_r` and define the
   least-squares target `S1 = Σ_{uvw} (Σ_r a_r[u]b_r[v]c_r[w] − T[u,v,w])²`.
2. `S1` is trilinear, but for two of the three coefficient groups fixed it is
   *linear* in the third, so the minimum is reached by iterating three exact
   linear least-squares solves (alternating least squares, ALS). This is
   `scripts/approx4x4/batch_als.py`, batched over restarts and using the
   MTTKRP + normal-equation form so a sweep costs `O(S·R·(N²+R²))`.
3. Eq. (4)–(5) adds a penalty pulling coefficients towards "model" values so
   that the numeric solution can be discretised into a Laurent-polynomial
   (functional) solution; the practical algorithm is that polynomial evaluated
   at a small `x`. The 3x3 rank-20 kernel in this repo (`algorithms/m_3x3.txt`,
   `C_3x3.txt`) is exactly Table 6 of the paper evaluated at `x = 2^-7`.

Everything below uses step 1–2 (the numeric core of the method). Step 3 (the
guided discretisation that produces a *functional* solution) was not reproduced
for R=46; see §5.

## 2. Calibration: what the tensor error means

`‖T − T_R‖_F / ‖T‖_F` (tensor error) is only a proxy for the error that
`src/benchmark.c` measures (`max|C_alg − C| / max|C|` on uniform `[−1,1]`
inputs). Measured relationship:

| algorithm | rank | tensor err | benchmark err (N=8192) |
| --- | --- | --- | --- |
| 3x3 (Smirnov, border rank 20) | 20 | 5.6e-3 | 1.7e-2 |
| 4x4r47 | 47 | 1.25e-1 | 3.8e-1 |
| 4x4r46 | 46 | 1.77e-1 | 4.0e-1 |
| 4x4r43 | 43 | 2.80e-1 | 5.9e-1 |
| 4x4 (exact) | 48 | 0 | 2e-14 |

The benchmark error is roughly `2–2.5 ×` the tensor error. **A 20 % budget
therefore needs a tensor error of about 8 %.**

## 3. Search results for 4x4x4

`scripts/approx4x4/warm_start.py` walks the rank down from the exact rank-48
solution: to go from `R+1` to `R` terms it drops one term and merges random
pairs into their best rank-one approximation (higher-order power method), then
refines 256 candidates with batched ALS.

| rank R | ω = log₄R | tensor err |
| --- | --- | --- |
| 48 (exact) | 2.7925 | 0 |
| 47 | 2.7773 | 1.250e-1 |
| 46 | 2.7618 | 1.768e-1 |
| 45 | 2.7459 | 2.176e-1 |
| 44 | 2.7297 | 2.510e-1 |
| 43 | 2.7131 | 2.801e-1 |

A 768-restart multi-strategy search (`final_search.py`: drops, merges, gauge
scaling, 2x2x2 compositions, respawn mutations, random) reproduces rank 43 at
2.799e-1 — no better. Degenerate log-uniform initialisations
(`degenerate_search.py`), ridge continuation (`ridge_continuation.py`), large
scale starts and metric-targeted SGD (`metric_search.py`, minimising the
benchmark metric directly) all fail to beat the drop ladder.

## 4. Why ranks below 46 are expensive: the border-rank cliff

The rank of 4x4x4 is ≤ 48 and its **border rank is ≤ 46** (Smirnov). Because the
border rank is the *infimum*, a rank-46 scheme has error → 0 only in a limit
with unbounded coefficients; going *below* it costs a lot. Two independent
calibrations, computed here:

| tensor | border rank | error at border rank | error one rank below |
| --- | --- | --- | --- |
| 2x2x2 | 7 | 0 | **3.54e-1** at rank 6 (globally optimal: ALS and Gurobi both hit `1/√8`) |
| 3x3x3 | 20 | 5.6e-3 | **2.8e-1 … 3.5e-1** at rank 19 |

So the error does not grow gradually below the border rank — it jumps to
25–35 % immediately. The 4x4x4 ladder above is consistent with that pattern.

### The 2x2x2 composition route is also dead

`R(4,4,4) ≤ R(2,2,2)²`; using an approximate rank-6 2x2x2 in one slot gives a
rank-42 scheme (`compose2x2.py`), but its tensor error is **3.54e-1** — identical
to the rank-6 2x2x2 error, because the exact outer algorithm just transports the
inner error. ALS cannot improve the composed point at all: it is a fixed point
of the alternating solves (residual² = 8.0 exactly).

### Gurobi

`scripts/approx4x4/gurobi_4x4.py` builds the structure-aware non-convex QCQP
(one linearisation layer, `p[(i,j,k),r] = a·b`, then `Σ_r p·c = δ`: 1024 bilinear
equations instead of 4096 trilinear ones) and solves it with `NonConvex=2`.
Results:

* 2x2x2, K=6: best objective 1.0 → rel. err 3.535e-1, matching ALS ⇒ the
  `1/√8` value looks like the true global optimum.
* 3x3x3, K=19: 300 s / 900 s of spatial branch & bound only reached 9.8e-1 —
  far **worse** than the 2.8e-1 that ALS finds in seconds. Warm-starting from the
  ALS solution (700 s) does not help either: Gurobi abandons the incumbent and
  finishes at 9.813e-1 again.
* 4x4x4, R=43 (warm started from the ALS solution, 900 s, 593 nodes): objective
  60 vs. 5.02 for the ALS solution — Gurobi could not even match the warm start.

Conclusion: for these highly non-convex rank problems Gurobi's global solver is
not competitive with multi-start ALS; the barrier is the landscape, not the
solver's local search.

## 5. Outcome against the target

Target (to beat the 3x3 rank-20 scheme, `ω = log₃20 = 2.7268`):
**rank ≤ 43 with a matrix-multiplication relative error ≤ 20 %.**

| | rank | ω | benchmark error |
| --- | --- | --- | --- |
| requirement | ≤ 43 | ≤ 2.7268 | ≤ 2e-1 |
| best achieved | 43 | 2.7131 | 4.1e-1 … 5.9e-1 |
| lower error, too high rank | 47 | 2.7773 | 2.6e-1 … 3.8e-1 |

**The requirement is not met, and the evidence says it cannot be met this way.**
The two constraints pull in opposite directions:

* beating `ω = 2.727` with a 4x4 kernel forces rank ≤ 43, i.e. **three ranks
  below the border rank 46**;
* the border-rank cliff shows that even *one* rank below the border rank already
  costs ≈ 25–35 % error (2x2x2, 3x3x3), and the rank-43 4x4x4 solution sits at a
  tensor error of 2.8e-1 ⇒ ≈ 40–60 % measured error.

The single favourable datapoint is the pure macro-block case: `fmm_4x4r43` on a
bare 4x4 product (`M=4`, `base=0`) measures **2.11e-1**, i.e. only just outside
the budget; the error grows to 4.4e-1 once recursion levels are added.

## 6. What is shipped

| kernel | rank | ω | tolerance in `benchmark.c` |
| --- | --- | --- | --- |
| `4x4r43` | 43 | 2.7131 | 2e-1 (documentation only — it fails) |
| `4x4r46` | 46 | 2.7618 | 2e-1 (fails) |
| `4x4r47` | 47 | 2.7773 | 2e-1 (fails) |

They are generated exactly like every other kernel
(`python3 scripts/generate_fmm.py 4x4r43`), verified against BLAS by
`tests/test_fmm.c` against loose regression tolerances, and benchmarked by
`./build/cfmm --alg 4x4r43`. They are kept because they are the best rank
reductions obtainable with this method and they document the rank/error
frontier; they are **not** numerically usable at the 20 % budget.

Regenerating:

```sh
python3 scripts/approx4x4/warm_start.py --top 48 --bottom 43 --restarts 256
python3 scripts/approx4x4/export_alg.py results/approx4x4/warm/warm_4x4_43.npz --name 4x4r43
python3 scripts/generate_fmm.py 4x4r43 4x4r46 4x4r47
cmake -S . -B build -DCFMM_ALGORITHMS="3x3;3x3x6;4x4;4x4r43;4x4r46;4x4r47" && cmake --build build -j
./build/cfmm --alg 4x4r43 --n 1024 --base 256 --check
```

## 7. What a real solution would require

1. **Reproduce Smirnov's functional rank-46 solution.** The paper states the
   (4,4,4;46) functional solution exists (2208 functions, 467 non-identical
   zeros) but does not print it. With it the rank-46 error is tunable to ~0, and
   — more importantly — it is the natural warm start for ranks 45…43, which is
   the only regime where the drop ladder might behave differently.
2. **A guided discretisation** (eq. (4)–(5)): iteratively clamp coefficients to
   a geometric lattice while re-solving the least-squares system, so the numeric
   solution collapses onto a Laurent-polynomial pattern. This is the part of the
   paper that turns a numeric solution into a *functional* one; it is a
   combinatorial search that Gurobi did not help with here (the products are
   trilinear, so no tractable MILP/MIQCP formulation was found).
3. Failing that, the honest conclusion is that the 4x4 format **cannot** beat the
   rank-20 3x3 scheme inside a 20 % error budget, and the practical route to a
   smaller exponent is a different format (or a genuinely new tensor
   decomposition, e.g. a rank-43 4x4x4 found by a discrete search such as the
   one that produced the rational rank-48 algorithm).
