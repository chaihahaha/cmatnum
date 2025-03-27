from pyomo.environ import *
import pyomo.environ as pyo
import numpy as np

# ----------------------------
# Define the target tensor T
# ----------------------------
T = np.zeros((9, 9, 9))
non_zero_indices = [
    (0, 0, 0), (0, 1, 3), (0, 2, 6), (1, 0, 1), (1, 1, 4), (1, 2, 7),
    (2, 0, 2), (2, 1, 5), (2, 2, 8), (3, 3, 0), (3, 4, 3), (3, 5, 6),
    (4, 3, 1), (4, 4, 4), (4, 5, 7), (5, 3, 2), (5, 4, 5), (5, 5, 8),
    (6, 6, 0), (6, 7, 3), (6, 8, 6), (7, 6, 1), (7, 7, 4), (7, 8, 7),
    (8, 6, 2), (8, 7, 5), (8, 8, 8)
]

for i, j, k in non_zero_indices:
    T[i, j, k] = 1


# ----------------------------
# Pyomo Model Setup (Linear Reformulation)
# ----------------------------
model = ConcreteModel()
allowed_values = [0, 1, -1, 1e-3, -1e-3, 1e3, -1e3]
rank = 17
n_values = len(allowed_values)
model.value_index = pyo.Set(initialize=range(n_values))

# ----------------------------
# Decision Variables (Binary)
# ----------------------------
model.A_vars = pyo.Var(
    range(9), range(rank), model.value_index,
    within=pyo.Binary, initialize=0
)
model.B_vars = pyo.Var(
    range(9), range(rank), model.value_index,
    within=pyo.Binary, initialize=0
)
model.C_vars = pyo.Var(
    range(9), range(rank), model.value_index,
    within=pyo.Binary, initialize=0
)

# ----------------------------
# Linear Constraints
# ----------------------------
# One-value selection constraints
model.one_value_A = pyo.Constraint(
    range(9), range(rank),
    rule=lambda m, i, j: sum(m.A_vars[i,j,v] for v in model.value_index) == 1
)
model.one_value_B = pyo.Constraint(
    range(9), range(rank),
    rule=lambda m, i, j: sum(m.B_vars[i,j,v] for v in model.value_index) == 1
)
model.one_value_C = pyo.Constraint(
    range(9), range(rank),
    rule=lambda m, i, j: sum(m.C_vars[i,j,v] for v in model.value_index) == 1
)

# ----------------------------
# Linear Objective Reformulation
# ----------------------------
# Precompute all possible product values
product_values = [a*b*c for a in allowed_values for b in allowed_values for c in allowed_values]

# New binary variables for product selection
model.product_sel = pyo.Var(
    range(9), range(9), range(9), range(rank), range(len(product_values)),
    within=pyo.Binary, initialize=0
)

# Constraints to link product selection with individual variables
def product_selection_rule(model, i, j, k, m, p):
    a_idx = p // (n_values**2)
    b_idx = (p // n_values) % n_values
    c_idx = p % n_values
    return model.product_sel[i,j,k,m,p] <= 0.5 * (
        model.A_vars[i,m,a_idx] + 
        model.B_vars[j,m,b_idx] + 
        model.C_vars[k,m,c_idx]
    )

model.product_constr = pyo.Constraint(
    range(9), range(9), range(9), range(rank), range(len(product_values)),
    rule=product_selection_rule
)

# Linear objective
model.obj = pyo.Objective(
    expr=sum(
        (sum(product_values[p] * model.product_sel[i,j,k,m,p] 
         for m in range(rank) for p in range(len(product_values))) - T[i,j,k]
        )**2 for i in range(9) for j in range(9) for k in range(9)),
    sense=pyo.minimize
)

# ----------------------------
# Solve with Gurobi
# ----------------------------
solver = pyo.SolverFactory('gurobi')
solver.options = {
    'TimeLimit': 3600,
    'MIPGap': 0.1,
    'Presolve': 2,
    'Threads': 4
}

results = solver.solve(model, tee=True)

# ----------------------------
# Post-Process Results (Unchanged)
# ----------------------------
if results.solver.termination_condition == pyo.TerminationCondition.optimal:
    print("\nSolution found!")
    A_sol = np.array([[model.A[i, m].value for m in range(rank)] for i in range(9)])
    B_sol = np.array([[model.B[j, m].value for m in range(rank)] for j in range(9)])
    C_sol = np.array([[model.C[k, m].value for m in range(rank)] for k in range(9)])
    
    # Reconstruct the tensor
    reconstructed = np.einsum("im,jm,km->ijk", A_sol, B_sol, C_sol)
    error = np.abs(reconstructed - T)
    
    print(f"Max error: {np.max(error):.4f}")
    print(f"Mean error: {np.mean(error):.4f}")
    print(f"Non-zero entries error: {np.mean(error[T == 1]):.4f}")
    print(f"Zero entries error: {np.mean(error[T == 0]):.4f}")
else:
    print("\nNo solution found. Try adjusting parameters.")
