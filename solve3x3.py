from pyomo.environ import *
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
M = 2000000000000.0       # Variable bounds
epsilon = 0.1  # Tolerance
rank = 17     # Factorization rank

# ----------------------------
# Decision Variables
# ----------------------------
# Matrix A: 9x17
model.A = Var(
    range(9), range(rank),
    bounds=(-M, M),
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)

# Matrix B: 9x17
model.B = Var(
    range(9), range(rank),
    bounds=(-M, M),
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)

# Matrix C: 9x17
model.C = Var(
    range(9), range(rank),
    bounds=(-M, M),
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)

# ----------------------------
# Tensor Approximation Constraints
# ----------------------------
model.tensor_constraints = ConstraintList()
for i, j, k in non_zero_indices:
    expr = sum(
        model.A[i, m] * model.B[j, m] * model.C[k, m]
        for m in range(rank)
    )
    model.tensor_constraints.add(expr >= 1 - epsilon)
    model.tensor_constraints.add(expr <= 1 + epsilon)

# ----------------------------
# Dummy Objective (Required by Ipopt)
# ----------------------------
# Small regularization to help convergence
model.obj = Objective(
    expr=1e-6 * (
        sum(model.A[i,m]**2 for i in range(9) for m in range(rank)) +
        sum(model.B[j,m]**2 for j in range(9) for m in range(rank)) +
        sum(model.C[k,m]**2 for k in range(9) for m in range(rank))
    ),
    sense=minimize
)

# ----------------------------
# Solve with Ipopt
# ----------------------------
solver = SolverFactory('ipopt')
solver.options = {
    'max_iter': 5000,
    'tol': 1e-4,
    'print_level': 5,
}

results = solver.solve(model, tee=True)

# ----------------------------
# Results Analysis
# ----------------------------
if results.solver.termination_condition == TerminationCondition.optimal:
    print("\nSolution found!")
    # Extract numpy arrays
    A_sol = np.array([[model.A[i,m].value for m in range(rank)] for i in range(9)])
    B_sol = np.array([[model.B[j,m].value for m in range(rank)] for j in range(9)])
    C_sol = np.array([[model.C[k,m].value for m in range(rank)] for k in range(9)])
    
    # Calculate reconstruction error
    reconstructed = np.einsum("im,jm,km->ijk", A_sol, B_sol, C_sol)
    error = np.abs(reconstructed - T)
    
    print(f"Max error: {np.max(error):.4f}")
    print(f"Mean error: {np.mean(error):.4f}")
    print(f"Constraints violated: {np.sum(error > epsilon)}")
    
    # Save results
    np.savez("tensor_factorization.npz", A=A_sol, B=B_sol, C=C_sol)
else:
    print("\nNo solution found. Try:")
    print("- Increasing epsilon (current: 0.01)")
    print("- Increasing max_iter (current: 5000)")
    print("- Using better initial guesses")
