import gurobipy as gp
from gurobipy import GRB
import numpy as np

# 定义张量T
T = np.zeros([9, 9, 9])
non_zero_indices = [(0, 0, 0), (0, 1, 3), (0, 2, 6), (1, 0, 1), (1, 1, 4), (1, 2, 7),
                    (2, 0, 2), (2, 1, 5), (2, 2, 8), (3, 3, 0), (3, 4, 3), (3, 5, 6),
                    (4, 3, 1), (4, 4, 4), (4, 5, 7), (5, 3, 2), (5, 4, 5), (5, 5, 8),
                    (6, 6, 0), (6, 7, 3), (6, 8, 6), (7, 6, 1), (7, 7, 4), (7, 8, 7),
                    (8, 6, 2), (8, 7, 5), (8, 8, 8)]
for i, j, k in non_zero_indices:
    T[i, j, k] = 1

# 初始化Gurobi模型
model = gp.Model()
model.Params.NonConvex = 2  # 允许非凸优化

# 参数设置
M = 2
epsilon = 0.01

# 创建变量：A、B、C及其二进制变量
A_vars = {}
A_bin = {}
for i in range(9):
    for m in range(17):
        A_bin[i, m] = model.addVar(vtype=GRB.BINARY, name=f'A_bin_{i}_{m}')
        A_vars[i, m] = model.addVar(lb=-M, ub=M, name=f'A_{i}_{m}')
        model.addConstr(A_vars[i, m] >= -M * A_bin[i, m])
        model.addConstr(A_vars[i, m] <= M * A_bin[i, m])

B_vars = {}
B_bin = {}
for j in range(9):
    for m in range(17):
        B_bin[j, m] = model.addVar(vtype=GRB.BINARY, name=f'B_bin_{j}_{m}')
        B_vars[j, m] = model.addVar(lb=-M, ub=M, name=f'B_{j}_{m}')
        model.addConstr(B_vars[j, m] >= -M * B_bin[j, m])
        model.addConstr(B_vars[j, m] <= M * B_bin[j, m])

C_vars = {}
C_bin = {}
for k in range(9):
    for m in range(17):
        C_bin[k, m] = model.addVar(vtype=GRB.BINARY, name=f'C_bin_{k}_{m}')
        C_vars[k, m] = model.addVar(lb=-M, ub=M, name=f'C_{k}_{m}')
        model.addConstr(C_vars[k, m] >= -M * C_bin[k, m])
        model.addConstr(C_vars[k, m] <= M * C_bin[k, m])

# 必须更新模型以确保变量属性可用
model.update()

# 添加张量近似约束
for i in range(9):
    for j in range(9):
        for k in range(9):
            target = T[i, j, k]
            if target == 0:
                continue  # 跳过零元素约束
            sum_expr = 0
            for m in range(17):
                a = A_vars[i, m]
                b = B_vars[j, m]
                c = C_vars[k, m]
                # 创建中间变量u表示三次乘积
                u = model.addVar(lb=-8, ub=8, name=f'u_{i}_{j}_{k}_{m}')
                # 正确方式：使用变量对象直接构建表达式
                model.addGenConstrNL(u, a*b*c)
                sum_expr += u
            # 添加精度约束
            model.addConstr(sum_expr <= target + epsilon, f"upper_{i}_{j}_{k}")
            model.addConstr(sum_expr >= target - epsilon, f"lower_{i}_{j}_{k}")

# 设置目标函数
obj = gp.quicksum(A_bin[i, m] for i in range(9) for m in range(17)) + \
      gp.quicksum(B_bin[j, m] for j in range(9) for m in range(17)) + \
      gp.quicksum(C_bin[k, m] for k in range(9) for m in range(17))
model.setObjective(obj, GRB.MINIMIZE)

# 求解模型
model.optimize()

# 输出结果
if model.status == GRB.OPTIMAL:
    print("最优解找到，目标值:", model.objVal)
else:
    print("未找到最优解，状态码:", model.status)
