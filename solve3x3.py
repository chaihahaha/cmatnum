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

# 参数设置
rank = 17  # 降低分解秩
M = 1e9
epsilon = 0.1  # 放宽精度

# 创建核心变量（连续型）
A = model.addVars(9, rank, lb=-M, ub=M, name="A")
B = model.addVars(9, rank, lb=-M, ub=M, name="B")
C = model.addVars(9, rank, lb=-M, ub=M, name="C")

# 添加非零元素约束
for i in range(9):
    for j in range(9):
        for k in range(9):
            target = T[i,j,k]
            expr = 0
            for m in range(rank):
                # 创建中间变量
                prod_abc = model.addVar(lb=-M**3, ub=M**3, name=f"prod_abc_{i}_{j}_{k}_{m}")
                
                # 分步构建三次项
                model.addGenConstrNL(prod_abc, A[i,m] * B[j,m] * C[k,m])  # 三次项
                expr += prod_abc
            
            # 添加精度约束
            model.addConstr(expr >= target - epsilon, name=f"lower_{i}_{j}_{k}")
            model.addConstr(expr <= target + epsilon, name=f"upper_{i}_{j}_{k}")

n_zeros = 0

for i in range(9):
    for j in range(rank):
        # For each element in A, B, C, create a binary variable indicating if it's within [-epsilon, epsilon]
        for i_mat, matrix in enumerate([A, B, C]):
            z = model.addVar(vtype=GRB.BINARY, name=f"z_{i}_{j}_{i_mat}")
            # If z == 1, then matrix[i,j] <= epsilon and matrix[i,j] >= -epsilon
            model.addGenConstrIndicator(z, 1, matrix[i,j] <= epsilon)
            n_zeros += z
            model.addGenConstrIndicator(z, 1, matrix[i,j] >= -epsilon)
            n_zeros += z

model.setObjective(n_zeros, GRB.MAXIMIZE)

def stop_at_feasible(model, where):
    if where == GRB.Callback.MIPSOL:
        print("找到可行解，终止求解")
        model.terminate()

# 求解模型
model.optimize(stop_at_feasible)

# 输出结果
if model.status == GRB.OPTIMAL:
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
else:
    print("未找到可行解，状态码:", model.status)
