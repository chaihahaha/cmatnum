# PITFALL — 踩坑记录

## 1. `limit_cse` 反向替换（原实现有 bug）

原 `gen_reduced_compgraph_*.py` 的 `limit_cse()` 按**下标递增**顺序把被丢弃的
CSE 临时量内联回保留的表达式里：

```python
for old, new in drop:                  # drop 是递增顺序
    replacements = [(sb, e.subs(old, new)) for sb, e in replacements]
    reduced_exprs = [e.subs(old, new) for e in reduced_exprs]
```

问题：某个被丢弃的临时量 `t_k` 的右端可能引用**更早被丢弃**的 `t_j (j<k)`。
处理 `t_k` 时会把 `t_j` 重新引入到已经清理过的表达式里，而 `t_j` 已经处理过了，
于是最终表达式里残留了指向不存在节点的符号。

`4x4` 张量上直接触发：84 个 CSE 替换只剩 2 个，其余表达式仍引用 `4x4_Ax28` 之类的
不存在节点 → `build_program` 抛 `KeyError`。

**修复**：按下标**递减**（依赖安全）顺序内联，见
`scripts/fmmgen/schedule.py:limit_cse()`。同时把“是否值得保留”的判据从
“立即操作数个数”改成“依赖的不同叶子个数”，更符合“值不值得占一块 scratch”的本意。

## 2. scratch buffer 复用导致的别名写坏（重要）

调度器会把“所有消费者都已排完”的临时块回收进池子。最初的 `assign_buffers()`
在遍历**当前节点自身的依赖**时就完成了回收，然后才给当前节点分配目标槽位——
于是目标槽位可能正好是它自己的某个（刚判定死亡的）输入块：

```c
matlincomb_double_init(scratch[2], 2, (double_cmat[]){scratch[2], scratch[5]}, ...);
```

`matlincomb_double_init()` 的第一步是 `dcopy(mats[0] -> res)`；当 `res == mats[0]`
时是自拷贝（无害），但当 `res == mats[k], k>0` 时，会把还没读的 `mats[k]` 覆盖掉。
`4x4` 的 `N=4` 用例上表现为结果错得离谱（相对误差 2.5/10）。

**修复**：输入块在消费者计算期间一直存活，所以必须先选目标槽位（禁止选中
自身输入的槽位），再把死亡输入块归还池子。见 `schedule.py:assign_buffers()`。
`_weighted_peak()` 的峰值模型也相应修正为“先把当前块算进去，再释放死亡输入”。

## 3. `is_contiguous_double` 与 `data[0]` 的隐含假设

`cmat` 用 `arena_shape[1]` 作为 leading dimension，`is_contiguous_double()` 只检查
`offset[1]==0 && arena_shape[1]==shape[1]`。只要切片“整列宽”，块就是连续的，
`data[0]` 就是块首地址。生成器依赖这一点：`A_i_j` 都是整列宽切片。
如果以后引入列偏移不为 0 的切片，所有 `cblas_*` 整块调用都会失效。

## 4. benchmark 去掉 `openblas_set_num_threads` 的弱符号

macOS + Accelerate 下 `__attribute__((weak_import))` 仍然会在链接期报
`Undefined symbols: _openblas_set_num_threads`。改成在第一次调用 BLAS 之前
`setenv("VECLIB_MAXIMUM_THREADS"/"OPENBLAS_NUM_THREADS"/"OMP_NUM_THREADS", ...)`，
既跨 BLAS 实现又不会引入链接依赖。

## 5. `--compare-schedulers` 里 close 后不能再用 probe

早期版本 `assign_buffers()` 一边回收一边 `dict.pop()`，返回值里丢失了大部分映射，
导致 `KeyError: '4x4_Ax64'`。现在分成 `assigned`（永久映射）和 `live`（回收簿记）。

## 6. 逐元素相对误差不能用来判断这类算法的正确性

`3x3` 是 rank-20 的 **近似**（border rank）算法，相对 `‖C‖` 的误差约 0.8%。
若按“每个元素除以自身”的相对误差判断，某些接近 0 的元素会得到 10²~10⁴ 的
“相对误差”。benchmark 现在统一用 `‖C−T‖∞ / ‖T‖`（`matrix_error()`），
并为每个算法设定各自的容差（`3x3` 为 1e-2，其余 1e-9）。

## 7. tmux / 后台任务

本机没有 GNU `timeout`（`timeout: command not found`）；`/bin/ps` 在沙箱下被拒。
按 AGENTS.md：长时间任务统一用 `tmux new -d -s <name>` 启动，用
`tmux capture-pane -p` 查看，`pgrep -fl` 确认进程。

## 8. 旧 `gen_3x3_code.py` 产出的 fmm_3x3 与新生成器的差异

重构后曾出现“新 fmm_3x3 比旧的误差大”的错觉：用 `base = N/3` 在 N=243/2187
上比较时，旧版给出**零误差**——因为旧版把阈值硬编码成 `height <= 10000`，
这些尺寸直接走了 BLAS 分支，根本没跑算法。

把旧版的阈值也换成 `fmm_base_block` 后重新比较（`tests/compare_legacy_3x3.c`，
旧产物保存在 `tests/legacy_fmm_3x3.c`）：

| N | 新 vs BLAS | 旧 vs BLAS | 新 vs 旧 |
| --- | --- | --- | --- |
| 243 | 1.0245e-02 | 1.0245e-02 | 1.55e-03 |
| 2187 | 1.0009e-02 | 1.0009e-02 | 2.59e-03 |
| 6561 | 1.6798e-02 | 1.6105e-02 | 3.35e-03 |

即两者精度一致，差异只在结合顺序（浮点舍入）层面。
**教训**：比较两个实现时先确认双方走的是同一条代码路径，否则会把
“旧版直接调 BLAS”误读成“旧版更准”。

## 9. 生成器的性能陷阱（32x32 规模）

把生成器从“每个算法一个脚本”统一之后，在 32x32（15136 个秩一项）上踩了三个坑：

1. **`_parse_linear_form()` 用 `expr += ...` 累加**：sympy 每次 `Add` 都会重新
   规范化/排序，15136 行 × ~32 项 → **428 秒**。改成最后一次性 `sp.Add(*terms)`
   后降到 **23 秒**。
2. **`limit_cse()` 是 O(n_kept × n_dropped) 次 `subs`**：在 4x4 上表现为结果错误
   （见第 1 条），在 32x32 上是纯粹的性能灾难。改成对拓扑有序的替换列表做
   一趟前向展开（用依赖已解析的表达式）后是线性的。
3. **`schedule_legacy()` / `schedule_legacy_split()` 用 networkx**：
   `g.remove_edge()` + 每一步 `g.out_degree()` + `list(g.successors())`，
   在 ~16000 个节点上是 O(V²) 次 networkx 调用，实际上会“卡住”。
   改成普通的邻接表 + Kahn 拓扑排序。

即便如此，`sympy.cse` 本身在 15136 个 32 项线性型上仍需 **~27 ms/表达式**
（约 7 分钟/侧，A/B 两侧），内存占用也很大；`order='none'` 并不更快。
因此 `src/fmm_32x32.c` 目前仍是**重构前生成器产出**的版本，
只做了两处最小改动以便接入新的 benchmark：
  * 增加 `fmm_32x32_fast_calls` / `fmm_32x32_blas_calls` 计数器；
  * 把硬编码阈值 `1024` 换成 `fmm_base_block`，并把“尺寸不整除就 `return -1`”
    改成回退到 `cblas_dgemm`（原来那样会静默返回未初始化的结果）。

`scripts/generate_fmm.py 32x32` 仍然可用，只是需要较长时间；
CSE 结果会缓存到 `cache/cse_32x32_*.pickle`，只需付一次代价。

## 10. `sympy.nsimplify` 会破坏"不漂亮"的精确有理系数（生成器 bug）

`scripts/fmmgen/codegen.py` 的 `_linear_terms()` 对每个系数调用 `sp.nsimplify()`，
本意是把 CSE 产生的浮点系数还原成好看的分数。但对一个**精确有理数**它也会先转成
浮点再反解闭形式，于是

    nsimplify(Rational(3514958, 77847587))
      -> 7*2**(8/181)*3**(116/181)*5**(29/362)*7**(113/362)/675

随后 `sp.Rational(...)` 抛 `TypeError: invalid input`，`generate_fmm.py` 生成
带随机有理系数的算法时直接失败（含 2 的幂系数的 3x3/4x4 恰好不触发）。

**修复**：新增 `_nice()`，`coeff.is_Rational` 时原样返回，否则才
`sp.nsimplify(coeff, rational=True)`。

## 11. 4x4x4 低秩近似：border rank 是一个"悬崖"而不是斜坡

想做 rank ≤ 43 的 4x4 近似算法（为把 omega 压到 log_3(20)=2.7268 以下）时，
反复撞到同一堵墙：**一旦低于 border rank，误差不是慢慢变大，而是直接跳到 25–35%**。

- 2x2x2：border rank = rank = 7，rank-6 的全局最优是 1/√8 ≈ 3.54e-1
  （多起点 ALS 与 Gurobi `NonConvex=2` 给出同一个值，所以很可能是真的全局最优）。
- 3x3x3：border rank = 20，rank-20（Smirnov Table 6 @ x=2^-7）误差 5.6e-3；
  rank-19 立刻变成 2.8e-1。
- 4x4x4：border rank = 46；rank 47/46/45/44/43 的张量误差
  1.25e-1 / 1.77e-1 / 2.18e-1 / 2.51e-1 / 2.80e-1。

**教训**：不要把 border rank 当成"可以再往下砍几级"的预算。想再降 rank，
需要有该 rank 上的**结构化（Laurent 多项式）解**，而不是从上一个解砍项 + 局部优化；
后者只会落进 `sqrt(k)/8` 那族"丢单项式"的局部极小。

## 12. Gurobi 在这类三线性张量分解上通常打不过多起点 ALS

`NonConvex=2` 的空间分支定界对 4096 个三线性方程（线性化后 ~4.7e4 个双线性项）
完全没有竞争力：3x3x3 rank-19 跑 900 s 只到 9.8e-1（ALS 秒级给 2.8e-1），
4x4x4 rank-43 热启动 900 s 目标值 60（ALS 是 5.0）。小规模（2x2x2，K=6/7）
可以用来**验证** ALS 是否到达全局最优，但别指望它在大规模上找解。
另外 `gurobi_cp.py` 的 `--warm-dir` 文件名约定要和实际 npz 名字对齐，
否则热启动会静默失效、从头开始（本轮踩过一次）。
