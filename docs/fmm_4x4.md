# 4x4x4, rank 48 —— ω = 2.792481250

## 输入

`assets/4x4x4_tensor.mpl` 用 Maple 的 `TriadSet` 给出该算法：

```maple
Tensor := TriadSet([ Triad(A_1, B_1, C_1), ..., Triad(A_48, B_48, C_48) ]);
map(expand, A.B - add(Trace(Transpose(op([1,i,1,1],Tensor)).A)
                    * Trace(Transpose(op([1,i,1,2],Tensor)).B)
                    * Transpose(op([1,i,1,3],Tensor)), i = 1..48));
```

即

```
A·B = Σ_{r=1..48} <A_r, A> · <B_r, B> · C_rᵀ
```

（`assets/4x4x4_raw.mpl` 是同一个算法的 `FastMatMul` 展开形式，
来自 fmm.univ-lille.fr，只作为交叉参考；生成器使用的是张量形式。）

`scripts/fmmgen/algorithm.py:load_from_triadset()` 解析这个文件，
`Algorithm.verify()` 用 sympy 符号地验证 `Σ_r <A_r,A><B_r,B>C_rᵀ == A·B`：

```
n triads: 48
convention C_i^T: exact=True
coefficients: [-1, -1/2, -1/4, -1/8, 0, 1, 1/2, 1/4, 1/8]
```

系数全部是 2 的幂 → 算法是**精确**的（不是 border-rank 近似），
而且乘除都是二进制精确的，数值上比用无理系数的方案更稳。

指数：

```
ω = log_4 48 = ln 48 / ln 4 = 2.792481250360578
```

## 转换到项目格式

`scripts/generate_fmm.py 4x4 --emit-txt algorithms` 会把张量写成项目原有的
`m_*.txt` / `C_*.txt` 文本格式（`algorithms/m_4x4.txt`、`algorithms/C_4x4.txt`），
例如

```
m_1=(A_1_1+A_1_2-…)*(B_1_1-B_2_1+…),
C_1_1=1/8*m_3+…,
```

`load_from_triadset()` 与 `load_from_txt()` 产生同一个 `Algorithm` 对象，
所以两条路径生成的 C 代码是等价的。

## 生成的 C 代码

`src/fmm_4x4.c`（由生成器产出，约 48 KiB）：

```c
int fmm_4x4(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint M = A.shape[0], Kd = A.shape[1], Nd = B.shape[1];
    if (B.shape[0] != Kd || C.shape[0] != M || C.shape[1] != Nd ||
        !(M % 4 == 0 && Kd % 4 == 0 && Nd % 4 == 0) ||
        M <= (shape_uint)fmm_base_block) {
        fmm_4x4_blas_calls++;
        cblas_dgemm(...);                    /* 基准情形：直接 BLAS */
        return 0;
    }
    fmm_4x4_fast_calls++;
    const shape_uint BLHA = M/4, BLWA = Kd/4, BLHB = Kd/4, BLWB = Nd/4;
    const shape_uint BLHC = M/4, BLWC = Nd/4;
    double_cmat scratch[34];                 /* CSE 临时块（池化复用） */
    ...
    /*--- scheduled evaluation ---*/
    matlincomb_double_init(scratch[0], 4, (double_cmat[]){A_1_1, A_2_1, A_4_1, A_3_1},
                                          (double[]){1.0, 1.0, 1.0, -1.0});
    matlincomb_double_init(tmpA, 1, (double_cmat[]){scratch[0]}, (double[]){-1.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_1_1, B_3_1}, (double[]){1.0, 1.0});
    fmm_4x4(m, tmpA, tmpB);                  /* 递归 */
    cblas_daxpy(NC, -0.5, m.data[0], 1, C_4_1.data[0], 1);
    ...
}
```

要点：

* **递归**到 `M <= fmm_base_block` 才调用 BLAS，`fmm_base_block` 是运行期可调的全局量，
  方便 benchmark 扫阈值。
* `matlincomb_double_init()` 是本次新增的库函数：
  `res = Σ c_i·mats[i]`，用 `dcopy`+`dscal`+`daxpy` 完成，
  不需要先清零、也不需要系数是整数（原 `matlincomb_double_contiguous()` 要求 `int8_t`）。
* 若某个秩一项的 A 侧（或 B 侧）线性型只剩**一项**，就把那一项直接传给递归调用，
  并把常数因子折叠进 C 的累加系数 —— 省掉一次整块拷贝。例如上面
  `-scratch[0]` 的情形会变成常数 `-1` 乘进 `C` 系数。
* 所有临时块共用 34 个池化槽位（见 `docs/eval_order.md`），
  而不是每条秩一项各分配一套。

## 参数与产物

| 项 | 值 |
| --- | --- |
| rank | 48 |
| 宏块划分 | A: 4×4, B: 4×4, C: 4×4 |
| CSE 临时块 | 59（A 侧 34 + B 侧 25） |
| scratch 槽位 | 34 |
| 峰值 scratch | 1.75 N² |
| 生成代码体积 | 48 KiB |
| 理论指数 | 2.792481250 |

## 正确性

* `tests/test_fmm4_tiny.c`：`N = 4`、`fmm_base_block = 0` 的单个 4×4 块，
  与 BLAS 的差为 **0**。
* `./build/cfmm --alg 4x4 --n N --base N/4 --check`：与 BLAS 相比的相对误差
  `‖C−T‖∞/‖T‖∞` 在机器精度量级（< 1e-15）。
