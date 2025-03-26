from pyomo.environ import *
import numpy as np

#x=1e-3
#
#_2x2 = 2*x**2
#_2x3 = 2*x**3
#x2 = x**2
#x3 = x**3
#x4 = x**4
#xi = 1/x
#x2i = 1/(x**2)
#
#B_coeffs = [x,0,0,-1,0,0,x,x,0,0,0,0,0,-1,0,0,0,0,0,0,
#0,0,0,x,0,0,-_2x2,0,0,0,0,x2,0,x,0,-x2,0,0,0,0,
#-x3,x3,0,0,-x3,0,0,-x3,0,0,0,0,0,x2,0,0,0,0,0,0,
#0,x2i,-xi,0,x2i,0,0,-x2i,-x2i,0,x2i,-x2i,-1,0,0,x2i,0,-xi,-1,x2i,
#0,-xi,1,0,0,0,0,0,xi,0,0,0,x,0,0,0,0,1,0,0,
#0,0,0,0,0,0,0,1,0,0,-1,1,0,0,0,0,0,x,x2,0,
#xi,0,0,-x2i,0,x2i,x2i,xi,0,0,0,0,x2i,-x2i,0,0,xi,0,0,0,
#0,0,-x2i,xi,0,-xi,-xi,0,0,x2i,0,1,-xi,xi,0,-1,0,0,0,0,
#x2i,-x,0,0,x2i,0,0,0,0,0,0,0,0,0,x2i,0,0,0,x2i,0,]
#B_coeffs = np.array(B_coeffs).reshape([9, 20])
#
#C_coeffs=[1,0,0,x,1,0,x,0,0,0,0,0,0,0,0,1,0,0,0,0,
#x,0,0,0,x,0,0,0,0,0,0,0,0,0,0,0,-x,0,0,x,
#0,0,0,0,0,x2,x3,x,0,x3,x,0,0,0,0,0,x3,0,0,0,
#xi,0,xi,1,xi,x2i,xi,0,0,xi,0,0,x2i,0,0,xi,xi,0,0,0,
#0,0,1,0,0,0,0,0,x,1,0,0,0,0,0,-1,0,0,0,1,
#0,x3,-x2,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,1,0,0,
#x2i,0,0,xi,x2i,0,0,x2i,0,0,0,x2i,0,xi,0,x2i,0,0,0,0,
#0,0,0,0,xi,0,0,0,0,0,1,0,0,0,x2i,0,0,0,x2i,xi,
#_2x3,xi,0,0,x3,0,0,0,xi,0,0,0,0,0,-x2,0,-_2x3,xi,0,x3,]
#C_coeffs = np.array(C_coeffs).reshape([9, 20])
#
#A_coeffs=[0,-x,x,-xi,0,1,-xi,0,-x,x,0,0,-x,xi,0,0,0,0,0,0,
#x2i,0,0,x2i,-x2i,-1,0,0,0,-1,0,0,0,0,xi,x2i,x2i,0,0,x2i,
#0,x2i,-x2i,0,0,-x2i,0,x2i,x2i,-x2i,x2i,-x2i,x2i,x2i,-x2i,0,0,0,x2i,0,
#-x2,-x,(x+-x4),0,x2,0,0,(-x+x2),-x,x,-x,x,x4,-x,-x3,0,0,0,0,0,
#0,1,0,0,0,0,0,0,(1+-x3),0,0,0,0,0,-1,0,0,x2,1,x,
#0,x,0,0,0,0,0,0,0,0,x,0,0,0,-x,0,0,1,x,0,
#x4,0,0,x4,0,(-x2+-x3),x,0,0,0,0,0,0,0,0,0,x,0,0,0,
#0,0,0,0,0,x2,0,0,0,x2,0,0,0,0,x4,0,-1,0,0,0,
#0,-1,1,0,0,1,0,0,-1,1,0,0,-1,0,0,0,0,0,0,0,]
#A_coeffs = np.array(A_coeffs).reshape([9, 20])
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
M = 1e20      # Variable bounds
rank = 20    # Factorization rank

# ----------------------------
# Decision Variables
# ----------------------------
model.A = Var(
    range(9), range(rank),
    bounds=(-M, M),
    #initialize=lambda m, i, j: A_coeffs[i,j]
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)
model.B = Var(
    range(9), range(rank),
    bounds=(-M, M),
    #initialize=lambda m, i, j: B_coeffs[i,j]
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)
model.C = Var(
    range(9), range(rank),
    bounds=(-M, M),
    #initialize=lambda m, i, j: C_coeffs[i,j]
    initialize=lambda m, i, j: np.random.uniform(-0.1, 0.1)
)

# ----------------------------
# Objective: Minimize Total Squared Error
# ----------------------------
def total_error(model):
    error = 0.0
    for i in range(9):
        for j in range(9):
            for k in range(9):
                expr = sum(
                    model.A[i, m] * model.B[j, m] * model.C[k, m]
                    for m in range(rank)
                )
                target = T[i, j, k]
                error += (expr - target)**2
    return error

model.obj = Objective(rule=total_error, sense=minimize)

# ----------------------------
# Solve with Ipopt
# ----------------------------
solver = SolverFactory('ipopt')
solver.options = {
    'max_iter': 5000,
    'tol': 1e-6,
    'print_level': 5
}

results = solver.solve(model, tee=True)

# ----------------------------
# Post-Process Results
# ----------------------------
if results.solver.termination_condition == TerminationCondition.optimal:
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
