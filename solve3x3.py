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
# Pyomo Model Setup
# ----------------------------
model = ConcreteModel()

# Parameters
allowed_values = [0, 1, 1e3, 1e6, 1e-3, 1e-6, 1e-9, 1e-12]
rank = 17
n_values = len(allowed_values)  # Should be 8

# Create an index set for allowed values
model.value_index = pyo.Set(initialize=range(n_values))

# ----------------------------
# Modified Decision Variables
# ----------------------------
# Binary variables: x[i,j,v] = 1 if A[i,j] = allowed_values[v]
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
# New Constraints
# ----------------------------
# Each position must select exactly one value
def one_value_rule_A(model, i, j):
    return sum(model.A_vars[i,j,v] for v in model.value_index) == 1
model.one_value_A = pyo.Constraint(range(9), range(rank), rule=one_value_rule_A)

def one_value_rule_B(model, i, j):
    return sum(model.B_vars[i,j,v] for v in model.value_index) == 1
model.one_value_B = pyo.Constraint(range(9), range(rank), rule=one_value_rule_B)

def one_value_rule_C(model, i, j):
    return sum(model.C_vars[i,j,v] for v in model.value_index) == 1
model.one_value_C = pyo.Constraint(range(9), range(rank), rule=one_value_rule_C)

# ----------------------------
# Modified Objective Function
# ----------------------------
def total_error(model):
    error = 0.0
    for i in range(9):
        for j in range(9):
            for k in range(9):
                expr = 0.0
                for m in range(rank):
                    # Calculate A[i,m] * B[j,m] * C[k,m] using binary variables
                    a_val = sum(allowed_values[v] * model.A_vars[i,m,v] for v in model.value_index)
                    b_val = sum(allowed_values[v] * model.B_vars[j,m,v] for v in model.value_index)
                    c_val = sum(allowed_values[v] * model.C_vars[k,m,v] for v in model.value_index)
                    expr += a_val * b_val * c_val
                target = T[i, j, k]
                error += (expr - target)**2
    return error

model.obj = pyo.Objective(rule=total_error, sense=pyo.minimize)

# ----------------------------
# Solve with SCIP (Changed solver)
# ----------------------------
solver = pyo.SolverFactory('scip')
solver.options = {
    'limits/time': 7200,        # 2-hour timeout
    'limits/gap': 0.05,         # 5% optimality gap
    'presolving/maxrounds': 3,  # Moderate presolving
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
