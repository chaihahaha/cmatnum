# MEMO — 项目记忆 / 进度 / 决策

## 本轮目标（用户请求）

1. 实现 assets 里新的 2.792481250（rank-48 4x4x4）算法；
2. 重构代码（Python 生成器 + C 端）；
3. 研究现有的“子分块矩阵乘法求值顺序优化”能否继续改进；
4. benchmark 复杂度，并限制 benchmark 的 RAM 用量防止爆内存。

## 已完成

- [x] 解析 `assets/4x4x4_tensor.mpl` 的 TriadSet（48 个 Triad），
      用 sympy 符号验证 `A·B = Σ_r <A_r,A><B_r,B>C_rᵀ` 精确成立；
      系数全部是 2 的幂。导出 `algorithms/m_4x4.txt` / `C_4x4.txt`。
- [x] 统一生成器 `scripts/fmmgen/`（`algorithm.py` / `schedule.py` / `codegen.py`）
      + CLI `scripts/generate_fmm.py`，取代原来 4 个互相复制的 `gen_*.py`。
- [x] 生成 `src/fmm_4x4.{c,h}`，并把 `3x3` / `3x3x6` 也改成同一套生成器产出。
      3x3 的 S/T/M 系数从 `scripts/legacy/gen_3x3_code.py` 抽到
      `algorithms/{m,C}_3x3.txt`（`scripts/import_smirnov_3x3.py`）。
- [x] 目录重构：`src/`、`algorithms/`、`scripts/`、`scripts/legacy/`、`docs/`、
      `tests/`、`results/`、`imgs/`、`cache/`；CMake 按 `CFMM_ALGORITHMS` 选择内核。
- [x] 求值顺序优化：把 A/B 两侧放进同一张依赖图做面积感知调度，
      并修正 buffer 池的别名约束（详见 `docs/eval_order.md`）。
      峰值 scratch：3x3 −20%、3x3x6 −29%、4x4 −28%。
- [x] benchmark `src/benchmark.c`：`--alg/--n/--levels/--base/--mem-limit/
      --check/--blas/--repeat/--csv`，带内存配额与整数乘法计数器。
- [x] 结果：4x4 在 16384³ 比 BLAS 快 12%，3x3 在 19683³ 快 25%；
      乘法次数标度精确给出 ω = 2.792481250。见 `docs/benchmark.md`。

## 待办 / 可能后续

- [ ] `32x32` 内核目前仍是旧生成器产出的版本（`src/fmm_32x32.c`，25 MiB）。
      用新生成器重跑需要 sympy 对 15136 个表达式做 CSE，
      解析已从 428 s 优化到 23 s，CSE 约 15~20 min，结果会缓存到 `cache/`。
- [ ] 把 C 的累加融进递归（`cblas_dgemm` 的 `beta` 累加）以省掉 `m`/`C_x` 往返。
- [ ] 基准情形换成针对 256/512 小块手工向量化的核（目前直接调 `dgemm`，
      小块效率只有大块的 1/4，这是快速算法在中等规模输给 BLAS 的主因）。
- [ ] `legacy` 调度优先级里的 `index_of_last_use` 方向可疑，
      可以试试改成升序或换成“最远下次使用”启发式。
- [ ] `solve3x3.py`（GUROBI 求解 rank-17 3x3）与本轮改动无关，
      工作区里它的改动是用户自己的，未提交。

## 关键决策

- **算法表示统一为 `Algorithm` 数据类**：`a_forms` / `b_forms`（线性型）+ `c_terms`
  （输出组合）。Maple TriadSet、`m_*.txt`+`C_*.txt` 两种输入都归一到它。
- **不做系数缩放**：4x4 的系数是 2 的幂，直接用 `double` 系数，
  放弃原来 `int8_t` 系数 + 缩放的技巧（那个技巧要求系数是整数）。
  新增 `matlincomb_double_init()`：一次 `dcopy`+`dscal` 起步，
  不需要目的地预先清零，也不要求整数系数。
- **单操作数折叠**：如果某个秩一项的 A 侧线性型只剩一项 `c·X`，
  直接把 `X` 交给递归调用，把 `c` 折进 C 的累加系数，省一次整块拷贝。
- **调度器用“组合多个启发式 + 随机重启”** 而不是依赖单一贪心，
  因为单一规则在不同图上表现差异很大（3x3 上 legacy 最好，4x4/3x3x6 上贪心最好）。
- **内存配额放在 `cmat.c` 里做显式记账**（`cmat_memory_limit`），
  而不是只依赖 `setrlimit`：超限时打印原因并 `exit(2)`，
  同时 `benchmark` 再设一个 `RLIMIT_AS` 兜底。
- **正确性判据改为 `‖C−T‖∞ / ‖T‖∞`**，并给每个算法单独的容差
  （3x3 是近似算法，容差 5e-2；其余 1e-9）。

## 运行记录（生成器耗时）

| 算法 | 解析 | CSE | 生成 |
| --- | --- | --- | --- |
| 3x3（20 项） | <0.1 s | <0.1 s | 0.2 s |
| 3x3x6（40 项） | <0.1 s | <0.1 s | 0.3 s |
| 4x4（48 项） | 0.1 s | <0.1 s | 0.4 s |
| 32x32（15136 项） | 23 s（已从 428 s 优化） | ~15–20 min | 数十秒 |

## 常用命令

```sh
cmake -S . -B build -DCFMM_ALGORITHMS="3x3;3x3x6;4x4" && cmake --build build -j
python3 scripts/generate_fmm.py 4x4 --scheduler best
python3 scripts/generate_fmm.py --compare-schedulers 3x3 3x3x6 4x4
./build/cfmm --alg 4x4 --n 8192 --base 2048 --check --blas --repeat 2 --mem-limit 20000
scripts/run_benchmarks.sh && python3 scripts/plot_results.py
```
