# FYI — 背景知识与外部资料

## 名词

- **FMM (Fast Matrix Multiplication)**：递归分块、用更少标量乘法完成小矩阵乘法的算法族
  （Strassen 及其推广）。
- **rank / 双线性复杂度**：把 `<n,k,m>` 矩阵乘法写成 `C = Σ_r <A_r,A><B_r,B> C_r`
  所需的最少项数 `R`。递归使用时渐近指数 `ω = log_n R`。
- **TriadSet / Triad**：Maple 里表示上述张量分解的形式，每个 Triad 就是
  `(A_r, B_r, C_r)` 三个矩阵。
- **CSE (common subexpression elimination)**：公共子表达式消除。
  `sympy.cse` 用于把多个线性型里重复出现的子式和提取成临时块。
- **求值顺序调度 (list scheduling)**：给依赖图找一个线性求值顺序。
  目标是降低同时存活的临时块数量（= 峰值 scratch 内存）。

## 参考链接

- fmm.univ-lille.fr —— `FastMatMul` Maple 工具，本次 `4x4x4_raw.mpl` 就来自它。
  <https://fmm.univ-lille.fr>
- 快速矩阵乘法代码生成与实现：<https://github.com/arbenson/fast-matmul>
- Smirnov rank-20 3x3x3（近似 / border rank）：见 README 的 [8]。
- `sympy.cse` 文档：<https://docs.sympy.org/latest/modules/simplify/simplify.html#sympy.simplify.cse_main.cse>

## 数学身份

`assets/4x4x4_tensor.mpl` 中的 TriadSet 满足

```
C = Σ_{r=1..48} <A_r, A> · <B_r, B> · C_rᵀ
```

其中 `<X, Y> = Σ_{p,q} X[p,q]·Y[p,q]` 是 Frobenius 内积。
本仓库用 `Algorithm.verify()` 符号验证了这一点（系数全为 2 的幂，算法是精确的）。

指数：`log_4(48) = ln 48 / ln 4 = 2.792481250360578…`

## BLAS / 环境

- macOS 通过 Accelerate 提供 `cblas_*`（`cblas_new.h`，`ACCELERATE_NEW_LAPACK`）。
- `cblas_dgemm` 行主序：`lda ≥ K`，`A.data[0]` 是块首地址，`arena_shape[1]` 是 leading dimension。
- `dgemm` 在小块上效率急剧下降（本机 N=256 的 dgemm 约只有 N=8192 的 1/5 效率），
  这是 FMM 在实用尺寸上很难打败 BLAS 的主要原因。
