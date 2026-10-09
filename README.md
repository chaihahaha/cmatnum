# cmatnum

A small C library for numerical linear algebra, plus a **code generator for
recursive fast matrix-multiplication algorithms** (Strassen-like / "FMM"
schemes derived from bilinear tensor decompositions).

Given a rank-*R* bilinear description of a small matrix product, the generator
emits a recursive C routine that splits the operands into macro-blocks, forms
the linear combinations required by the algorithm's tensor, recurses on the
*R* independent sub-products and accumulates the results into `C`.  Below a
runtime-tunable block threshold the routines call `cblas_dgemm`.

## Layout

| Path | Contents |
| --- | --- |
| `src/` | C sources: matrix type (`cmat`), BLAS wrappers (`matmul`), benchmark, and the generated `fmm_*.c` kernels |
| `scripts/fmmgen/` | the generator: algorithm parsing, CSE, evaluation-order scheduling, C emission |
| `scripts/generate_fmm.py` | command-line front end |
| `scripts/legacy/` | the original per-algorithm generator scripts (kept for reference) |
| `algorithms/` | algorithm descriptions (`m_*.txt` rank-one forms, `C_*.txt` output forms) |
| `assets/` | Maple tensor decompositions (`*.mpl`) |
| `tests/` | small standalone numerical checks |
| `results/` | benchmark CSV output (regenerated) |
| `docs/` | design notes and reports |

## Algorithms

| Name | Rank | Blocks | Exponent |
| --- | --- | --- | --- |
| `3x3` | 20 | 3x3x3 | log₃ 20 = 2.727 (approximate, Smirnov border rank) |
| `3x3x6` | 40 | 3x3x6 | 40/54 of the naive work per level |
| `4x4` | 48 | 4x4x4 | log₄ 48 = **2.792481250** (exact) |
| `32x32` | 15136 | 32x32x32 | log₃₂ 15136 = 2.777 |

The `4x4` kernel is generated from `assets/4x4x4_tensor.mpl`, a Maple
`TriadSet` of 48 rank-one triads.  See `docs/fmm_4x4.md`.

## Build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

`fmm_32x32.c` is ~25 MiB of generated code; drop it for quick iterations:

```sh
cmake -S . -B build -DCFMM_ALGORITHMS="3x3;3x3x6;4x4"
```

## Tests

```sh
cmake --build build -j && ctest --test-dir build --output-on-failure
```

`tests/test_fmm.c` compares every built kernel against `cblas_dgemm` on
conforming and non-conforming shapes (the non-conforming cases must fall back
to BLAS).

## Generating kernels

```sh
python3 scripts/generate_fmm.py --list
python3 scripts/generate_fmm.py 4x4                 # -> src/fmm_4x4.{c,h}
python3 scripts/generate_fmm.py 3x3x6 --scheduler greedy --info
python3 scripts/generate_fmm.py --compare-schedulers 3x3 3x3x6 4x4
python3 scripts/generate_fmm.py 4x4 --emit-txt algorithms
```

Requirements: Python 3 with `sympy` and `networkx`.

## Benchmarking

```sh
./build/cfmm --list
./build/cfmm --all --levels 1 --base 512 --mem-limit 24000
./build/cfmm --alg 4x4 --n 16384 --base 4096 --check --blas --repeat 3
scripts/run_benchmarks.sh            # full sweep -> results/*.csv
```

`--mem-limit` caps the bytes handed out by the matrix helpers, and the process
sets a matching `RLIMIT_AS` backstop, so an oversized problem aborts with a
diagnostic instead of being killed by the OS.  Use `--levels L` to derive sizes
from the block split (`N = base · k^L`) which keeps the base-case block size
constant across a sweep — that is the setting in which the *algorithmic*
exponent is observable.

## References

[1] Karstadt, Elaye and Oded Schwartz. “Matrix Multiplication, a Little Faster.”
Journal of the ACM (JACM) 67 (2020): 1-31.

[2] Benson, Austin R. and Grey Ballard. “A framework for practical parallel
fast matrix multiplication.” PPoPP (2014).

[3] Schwartz, Oded et al. “Alternative Basis Matrix Multiplication is Fast and
Stable.” IPDPS (2024): 38-51.

[4] https://github.com/arbenson/fast-matmul

[5] https://fmm.univ-lille.fr

[6] Drevet, Charles-Éric et al. “Optimization techniques for small matrix
multiplication.” Theor. Comput. Sci. 412 (2011): 2219-2236.

[7] Respondek, J. S. (2025). Fast matrix multiplication with applications.
doi:10.1007/978-3-031-76930-6

[8] Smirnov, A.V. (2013). The bilinear complexity and practical algorithms for
matrix multiplication. Computational Mathematics and Mathematical Physics, 53,
1781-1795.
