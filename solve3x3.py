import gurobipy as gp
from gurobipy import GRB
import numpy as np

# 定义非零张量元素
T_nonzero = {
    (0, 0, 0): 1, (0, 1, 3): 1, (0, 2, 6): 1,
    (1, 0, 1): 1, (1, 1, 4): 1, (1, 2, 7): 1,
    (2, 0, 2): 1, (2, 1, 5): 1, (2, 2, 8): 1,
    (3, 3, 0): 1, (3, 4, 3): 1, (3, 5, 6): 1,
    (4, 3, 1): 1, (4, 4, 4): 1, (4, 5, 7): 1,
    (5, 3, 2): 1, (5, 4, 5): 1, (5, 5, 8): 1,
    (6, 6, 0): 1, (6, 7, 3): 1, (6, 8, 6): 1,
    (7, 6, 1): 1, (7, 7, 4): 1, (7, 8, 7): 1,
    (8, 6, 2): 1, (8, 7, 5): 1, (8, 8, 8): 1
}

T = np.zeros([9,9,9])
for i,j,k in T_nonzero:
    T[i,j,k] = 1

# 初始化模型
model = gp.Model()
model.Params.NonConvex = 2  # 启用非凸优化
model.Params.MIPGap = 6e-4

# 参数设置
rank = 17  # 降低分解秩
M = 1e9
epsilon = 1e-2  # 放宽精度

# 创建核心变量（连续型）
A = model.addVars(9, rank, lb=-M, ub=M, name="A")
B = model.addVars(9, rank, lb=-M, ub=M, name="B")
C = model.addVars(9, rank, lb=-M, ub=M, name="C")

n_matmul = 0

# 添加非零元素约束
for i in range(9):
    for j in range(9):
        for k in range(9):
            target = T[i,j,k]
            expr = 0
            for m in range(rank):
                expr += A[i,m] * B[j,m] * C[k,m]

            sum_ijk = model.addVar(lb=-M**3, ub=M**3, name="sum_{i}_{j}_{k}")
            model.addGenConstrNL(sum_ijk, expr)

            
            # 添加精度约束
            ml = model.addVar(vtype=GRB.BINARY, name=f"ml_{i}_{j}_{k}")
            mg = model.addVar(vtype=GRB.BINARY, name=f"mg_{i}_{j}_{k}")
            model.addGenConstrIndicator(ml, 1, sum_ijk >= target - epsilon)
            model.addGenConstrIndicator(mg, 1, sum_ijk <= target + epsilon)
            n_matmul += ml
            n_matmul += mg

n_zeros = 0

for i in range(9):
    for j in range(rank):
        # For each element in A, B, C, create a binary variable indicating if it's within [-epsilon, epsilon]
        for i_mat, matrix in enumerate([A, B, C]):
            zl = model.addVar(vtype=GRB.BINARY, name=f"zl_{i}_{j}_{i_mat}")
            zg = model.addVar(vtype=GRB.BINARY, name=f"zg_{i}_{j}_{i_mat}")
            # If z == 1, then matrix[i,j] <= epsilon and matrix[i,j] >= -epsilon
            model.addGenConstrIndicator(zl, 1, matrix[i,j] <= epsilon)
            n_zeros += zl
            model.addGenConstrIndicator(zg, 1, matrix[i,j] >= -epsilon)
            n_zeros += zg

model.setObjective(1e-3*n_zeros + n_matmul, GRB.MAXIMIZE)

# 求解模型
model.optimize()

# 输出结果
if model.status == GRB.OPTIMAL:
    print("找到可行解")
else:
    print("未找到可行解，状态码:", model.status)

A_np = np.zeros([9, rank])
B_np = np.zeros([9, rank])
C_np = np.zeros([9, rank])
for m in range(rank):
    A_np[:,m] = [A[i,m].X for i in range(9)]
    B_np[:,m] = [B[i,m].X for i in range(9)]
    C_np[:,m] = [C[i,m].X for i in range(9)]
solved_vars = {'A':A_np, 'B':B_np, 'C':C_np}
import pickle
with open("vars.pickle", "wb") as f:
    pickle.dump(solved_vars, f)
print(f"A = \n{A_np}")
print(f"B = \n{B_np}")
print(f"C = \n{C_np}")
error_tensor = np.abs(T-np.einsum("im,jm,km", A_np,B_np,C_np))
error_matrix = np.max(error_tensor, axis=0)
print(f"error = \n{error_matrix}")
