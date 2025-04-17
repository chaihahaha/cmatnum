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
assert np.sum(T) == 9*3

# 初始化模型
model = gp.Model()
model.Params.NonConvex = 2  # 启用非凸优化
#model.Params.MIPGap = 0.49
model.Params.NodefileStart = 20
model.Params.SoftMemLimit = 63
model.Params.Presolve = 2
model.Params.Method = 2

# 参数设置
rank = 17  # 降低分解秩
#M = GRB.INFINITY
M = 1e5
#epsilon = 1e-2  # 放宽精度

# 创建核心变量（连续型）
A = model.addVars(9, rank, lb=-M, ub=M, name="A")
B = model.addVars(9, rank, lb=-M, ub=M, name="B")
C = model.addVars(9, rank, lb=-M, ub=M, name="C")
epsilon = model.addVar(lb=0, ub=0.1, name="epsilon")
epsilon_eq = model.addVar(lb=0, ub=1e-4, name="epsilon_eq")

err_matmul = 0

# 添加非零元素约束
for i in range(9):
    for j in range(9):
        for k in range(9):
            target = T[i,j,k]
            expr = 0
            for m in range(rank):
                AB_mul = model.addVar(lb=-M, ub=M, name=f"AB_mul_{i}_{j}_{k}_{m}")
                ABC_mul = model.addVar(lb=-M, ub=M, name=f"ABC_mul_{i}_{j}_{k}_{m}")
                #ABdiff_mul = model.addVar(lb=-M, ub=M, name=f"ABdiff_mul_{i}_{j}_{k}_{m}")
                #ABCdiff_mul = model.addVar(lb=-M, ub=M, name=f"ABCdiff_mul_{i}_{j}_{k}_{m}")
                #model.addGenConstrNL(ABC_mul, A[i,m] * B[j,m] * C[k,m])
                model.addConstr(AB_mul - A[i,m] * B[j,m] <= epsilon_eq)
                model.addConstr(AB_mul - A[i,m] * B[j,m]>= -epsilon_eq)
                model.addConstr(ABC_mul - AB_mul * C[k,m]<= epsilon_eq)
                model.addConstr(ABC_mul - AB_mul * C[k,m]>=-epsilon_eq)
                
                expr += ABC_mul

            #sum_ijk = model.addVar(lb=-M, ub=M, name=f"sum_{i}_{j}_{k}")
            #diff = model.addVar(lb=-M, ub=M, name=f"diff_{i}_{j}_{k}")
            #model.addConstr(sum_ijk== expr)

            
            # 添加精度约束
            #err = model.addVar(lb=-M, ub=M, name=f"err_mat_{i}_{j}_{k}")
            #model.addConstr(diff== sum_ijk - target)
            #model.addConstr(diff== expr - target)
            expr -= target
            #model.addGenConstrAbs(diff, expr)
            #err_matmul += diff
            model.addConstr(expr<=epsilon)
            model.addConstr(expr>=-epsilon)

#err_zeros = 0
#
#for i in range(9):
#    for j in range(rank):
#        # For each element in A, B, C, create a binary variable indicating if it's within [-epsilon, epsilon]
#        for i_mat, matrix in enumerate([A, B, C]):
#            err = model.addVar(lb=-M, ub=M, name=f"err_zero_{i}_{j}_{k}")
#            model.addGenConstrAbs(err, matrix[i,j])
#            err_zeros += err

model.setObjective(epsilon+epsilon_eq*1e3, GRB.MINIMIZE)

# 求解模型
model.optimize()

# 输出结果
if model.status == GRB.OPTIMAL:
    print("找到可行解")
else:
    print("未找到可行解，状态码:", model.status)
solved_vars = {v.VarName: v.X for v in model.getVars()}
import pickle
with open("vars.pickle", "wb") as f:
    pickle.dump(solved_vars, f)

A_np = np.zeros([9, rank])
B_np = np.zeros([9, rank])
C_np = np.zeros([9, rank])
for m in range(rank):
    A_np[:,m] = [A[i,m].X for i in range(9)]
    B_np[:,m] = [B[i,m].X for i in range(9)]
    C_np[:,m] = [C[i,m].X for i in range(9)]
#solved_vars = {'A':A_np, 'B':B_np, 'C':C_np}
print(f"A = \n{A_np}")
print(f"B = \n{B_np}")
print(f"C = \n{C_np}")
error_tensor = np.abs(T-np.einsum("im,jm,km", A_np,B_np,C_np))
error_matrix = np.max(error_tensor, axis=(1,2))
print(f"error = \n{error_matrix}")

tolerance = 0.1
for constr in model.getConstrs():
    slack = constr.slack
    print(f'Constr {constr.ConstrName}, slack: {slack}')
