import gurobipy as gp
from gurobipy import GRB
import numpy as np

# å®ä¹å¼ éT
T = np.zeros([9, 9, 9])
non_zero_indices = [(0, 0, 0), (0, 1, 3), (0, 2, 6), (1, 0, 1), (1, 1, 4), (1, 2, 7),
                    (2, 0, 2), (2, 1, 5), (2, 2, 8), (3, 3, 0), (3, 4, 3), (3, 5, 6),
                    (4, 3, 1), (4, 4, 4), (4, 5, 7), (5, 3, 2), (5, 4, 5), (5, 5, 8),
                    (6, 6, 0), (6, 7, 3), (6, 8, 6), (7, 6, 1), (7, 7, 4), (7, 8, 7),
                    (8, 6, 2), (8, 7, 5), (8, 8, 8)]
for i, j, k in non_zero_indices:
    T[i, j, k] = 1

# åå§åGurobiæ¨¡å
model = gp.Model()
model.Params.NonConvex = 2  # åè®¸éå¸ä¼å

# åæ°è®¾ç½®
M = 2
epsilon = 0.01

# åå»ºåéï¼AãBãCåå¶äºè¿å¶åé
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

# å¿é¡»æ´æ°æ¨¡åä»¥ç¡®ä¿åéå±æ§å¯ç¨
model.update()

# æ·»å å¼ éè¿ä¼¼çº¦æ
for i in range(9):
    for j in range(9):
        for k in range(9):
            target = T[i, j, k]
            if target == 0:
                continue  # è·³è¿é¶åç´ çº¦æ
            sum_expr = 0
            for m in range(17):
                a = A_vars[i, m]
                b = B_vars[j, m]
                c = C_vars[k, m]
                # åå»ºä¸­é´åéuè¡¨ç¤ºä¸æ¬¡ä¹ç§¯
                u = model.addVar(lb=-8, ub=8, name=f'u_{i}_{j}_{k}_{m}')
                # æ­£ç¡®æ¹å¼ï¼ä½¿ç¨åéå¯¹è±¡ç´æ¥æå»ºè¡¨è¾¾å¼
                model.addGenConstrNL(u, a*b*c)
                sum_expr += u
            # æ·»å ç²¾åº¦çº¦æ
            model.addConstr(sum_expr <= target + epsilon, f"upper_{i}_{j}_{k}")
            model.addConstr(sum_expr >= target - epsilon, f"lower_{i}_{j}_{k}")

# è®¾ç½®ç®æ å½æ°
obj = gp.quicksum(A_bin[i, m] for i in range(9) for m in range(17)) + \
      gp.quicksum(B_bin[j, m] for j in range(9) for m in range(17)) + \
      gp.quicksum(C_bin[k, m] for k in range(9) for m in range(17))
model.setObjective(obj, GRB.MINIMIZE)

# æ±è§£æ¨¡å
model.optimize()

# è¾åºç»æ
if model.status == GRB.OPTIMAL:
    print("æä¼è§£æ¾å°ï¼ç®æ å¼:", model.objVal)
else:
    print("æªæ¾å°æä¼è§£ï¼ç¶æç :", model.status)
