import sympy as sp
import numpy as np
import pickle

# check precison of Smirnov 3x3x3 rank 20 approx matmul

threshold = 1e-3

x = sp.sympify(2)**(-7)
_2x2 = 2*x**2
_2x3 = 2*x**3
x2 = x**2
x3 = x**3
x4 = x**4
xi = 1/x
x2i = 1/(x**2)

S_coeffs = [x,0,0,-1,0,0,x,x,0,0,0,0,0,-1,0,0,0,0,0,0,
0,0,0,x,0,0,-_2x2,0,0,0,0,x2,0,x,0,-x2,0,0,0,0,
-x3,x3,0,0,-x3,0,0,-x3,0,0,0,0,0,x2,0,0,0,0,0,0,
0,x2i,-xi,0,x2i,0,0,-x2i,-x2i,0,x2i,-x2i,-1,0,0,x2i,0,-xi,-1,x2i,
0,-xi,1,0,0,0,0,0,xi,0,0,0,x,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,1,0,0,-1,1,0,0,0,0,0,x,x2,0,
xi,0,0,-x2i,0,x2i,x2i,xi,0,0,0,0,x2i,-x2i,0,0,xi,0,0,0,
0,0,-x2i,xi,0,-xi,-xi,0,0,x2i,0,1,-xi,xi,0,-1,0,0,0,0,
x2i,-x,0,0,x2i,0,0,0,0,0,0,0,0,0,x2i,0,0,0,x2i,0,]
S_coeffs = np.array(S_coeffs).reshape([9, 20])

T_coeffs=[1,0,0,x,1,0,x,0,0,0,0,0,0,0,0,1,0,0,0,0,
x,0,0,0,x,0,0,0,0,0,0,0,0,0,0,0,-x,0,0,x,
0,0,0,0,0,x2,x3,x,0,x3,x,0,0,0,0,0,x3,0,0,0,
xi,0,xi,1,xi,x2i,xi,0,0,xi,0,0,x2i,0,0,xi,xi,0,0,0,
0,0,1,0,0,0,0,0,x,1,0,0,0,0,0,-1,0,0,0,1,
0,x3,-x2,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,1,0,0,
x2i,0,0,xi,x2i,0,0,x2i,0,0,0,x2i,0,xi,0,x2i,0,0,0,0,
0,0,0,0,xi,0,0,0,0,0,1,0,0,0,x2i,0,0,0,x2i,xi,
_2x3,xi,0,0,x3,0,0,0,xi,0,0,0,0,0,-x2,0,-_2x3,xi,0,x3,]
T_coeffs = np.array(T_coeffs).reshape([9, 20])

M_coeffs=[0,-x,x,-xi,0,1,-xi,0,-x,x,0,0,-x,xi,0,0,0,0,0,0,
x2i,0,0,x2i,-x2i,-1,0,0,0,-1,0,0,0,0,xi,x2i,x2i,0,0,x2i,
0,x2i,-x2i,0,0,-x2i,0,x2i,x2i,-x2i,x2i,-x2i,x2i,x2i,-x2i,0,0,0,x2i,0,
-x2,-x,(x+-x4),0,x2,0,0,(-x+x2),-x,x,-x,x,x4,-x,-x3,0,0,0,0,0,
0,1,0,0,0,0,0,0,(1+-x3),0,0,0,0,0,-1,0,0,x2,1,x,
0,x,0,0,0,0,0,0,0,0,x,0,0,0,-x,0,0,1,x,0,
x4,0,0,x4,0,(-x2+-x3),x,0,0,0,0,0,0,0,0,0,x,0,0,0,
0,0,0,0,0,x2,0,0,0,x2,0,0,0,0,x4,0,-1,0,0,0,
0,-1,1,0,0,1,0,0,-1,1,0,0,-1,0,0,0,0,0,0,0,]
M_coeffs = np.array(M_coeffs).reshape([9, 20])

A = [[sp.Symbol(f'A_{i}_{j}') for j in range(3)] for i in range(3)]
A = np.array(A).flatten()
B = [[sp.Symbol(f'B_{i}_{j}') for j in range(3)] for i in range(3)]
B = np.array(B).flatten()
m = [sp.Symbol(f'm{i}') for i in range(20)]
m = np.array(m)

C = (A.reshape([3,3])@B.reshape([3,3])).flatten()
S_exprs = (A@S_coeffs)
T_exprs = (B@T_coeffs)
C_exprs = M_coeffs @ m
CC = M_coeffs@(S_exprs*T_exprs)

for i in range(len(CC)):
    expr = CC[i]
    # Expand the expression to multiply out all brackets
    expanded_expr = sp.simplify(sp.expand(expr))
    # Extract coefficients and corresponding terms
    terms_dict = expanded_expr.as_coefficients_dict()
    
    new_terms = []
    for term, coeff in terms_dict.items():
        # Evaluate the coefficient numerically
        coeff_num = coeff.evalf()
        # Check if the coefficient is a number and above the threshold
        if isinstance(coeff_num, sp.Number):
            if abs(coeff_num) >= threshold:
                new_terms.append(coeff * term)
        else:
            # Keep terms with symbolic coefficients
            new_terms.append(coeff * term)
    
    # Reconstruct the simplified expression
    new_expr = sp.Add(*new_terms)
    CC[i] = new_expr

print(C-CC)

m_to_C = {f"m{i}": [] for i in range(20)}
for i in range(3):
    for j in range(3):
        cidx = 3*i + j
        if C_exprs[cidx].is_Mul:
            args = [C_exprs[cidx]]
        else:
            args = C_exprs[cidx].args
        for carg in args:
            var = list(carg.free_symbols)[0]
            coeff = carg.coeff(var)
            var = str(var)
            coeff = sp.ccode(coeff)
            m_to_C[var].append((coeff, f"C_{i}_{j}"))

def generate_fmm_3x3_header():
    content = """\
#ifndef FMM_3x3_H
#define FMM_3x3_H

#include <stdio.h>
#include <stdlib.h>
#include "cmat.h"
"""
    content += """\
int fmm_3x3(double_cmat C, double_cmat A, double_cmat B);

#endif
"""
    with open("fmm_3x3.h", "w") as f:
        f.write(content)
    return

def generate_fmm_3x3_source():
    content = """\
#include "cmat.h"
#include "fmm_3x3.h"

int fmm_3x3(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint height = A.shape[0];
    shape_uint width = A.shape[1];
    if (height <= 10000 || width <= 10000 || !(height % 3 == width % 3 && height % 3 == 0 && height / 3 == width / 3)) {
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A.shape[1],
                    1.0, A.data[0], A.arena_shape[1],
                    B.data[0], B.arena_shape[1],
                    0.0, C.data[0], C.arena_shape[1]);
        return 0;
    }
    shape_uint N = height;
    shape_uint BL = N/3;
    shape_uint NS = BL*BL;
    double_cmat m;
    double_cmat S;
    double_cmat T;
    create_double_matrix(pairuint {BL, BL}, &m);
    create_double_matrix(pairuint {BL, BL}, &S);
    create_double_matrix(pairuint {BL, BL}, &T);
"""

    for j in range(3):
        content += (f"    double_cmat A_x_{j};\n")
        content += (f"    double_cmat B_x_{j};\n")
        content += (f"    double_cmat C_x_{j};\n")
    for j in range(3):
        content += (f"    create_slice_double_matrix_contiguous(&A_x_{j}, A, pairint {{ 0, N }}, pairint {{ {j}*BL, {j+1}*BL }});\n")
        content += (f"    create_slice_double_matrix_contiguous(&B_x_{j}, B, pairint {{ 0, N }}, pairint {{ {(j)}*BL, {j+1}*BL }});\n")
        content += (f"    create_double_matrix(pairuint {{ N, BL }}, &C_x_{j});\n")

    for i in range(3):
        for j in range(3):
            content += (f"    double_cmat A_{i}_{j} = slice_double_matrix(A_x_{j}, pairint {{{(i)}*BL, {i+1}*BL}}, pairint {{0, BL}});\n")
            content += (f"    double_cmat B_{i}_{j} = slice_double_matrix(B_x_{j}, pairint {{{(i)}*BL, {i+1}*BL}}, pairint {{0, BL}});\n")
            content += (f"    double_cmat C_{i}_{j} = slice_double_matrix(C_x_{j}, pairint {{{(i)}*BL, {i+1}*BL}}, pairint {{0, BL}});\n")

    for sidx in range(20):
        if S_exprs[sidx].is_Mul:
            args = [S_exprs[sidx]]
        else:
            args = S_exprs[sidx].args
        for S_arg in args:
            var = list(S_arg.free_symbols)[0]
            coeff = S_arg.coeff(var)
            var = str(var)
            coeff = sp.ccode(coeff)
            content += f"""
    cblas_daxpy(NS, {coeff}, {var}.data[0], 1, S.data[0], 1);
"""
        tidx = sidx
        if T_exprs[tidx].is_Mul:
            args = [T_exprs[tidx]]
        else:
            args = T_exprs[tidx].args
        for T_arg in args:
            var = list(T_arg.free_symbols)[0]
            coeff = T_arg.coeff(var)
            var = str(var)
            coeff = sp.ccode(coeff)
            content += f"""
    cblas_daxpy(NS, {coeff}, {var}.data[0], 1, T.data[0], 1);
"""
        midx = sidx
        content += """\
    fmm_3x3(m, S, T);
"""

        for coeff, C_name in m_to_C[f"m{midx}"]:
            content += f"    cblas_daxpy(NS, {coeff}, &m.data[0][0], 1, &{C_name}.data[0][0], 1);\n"
        for reset_var in ['S', 'T']:
            content+= f"    for(shape_uint arenai=0; arenai<NS; arenai++) {reset_var}.arena[arenai] = 0;\n"
    for j in range(3):
        content += f"    assign_double_slice(C, C_x_{j}, pairint {{0, N}}, pairint {{ {(j)}*BL, {j+1}*BL }});\n"
    for i in range(3):
        for j in range(3):
            content += (f"    free_double_matrix(A_{i}_{j});\n")
            content += (f"    free_double_matrix(B_{i}_{j});\n")
            content += (f"    free_double_matrix(C_{i}_{j});\n")
    for j in range(3):
        content += (f"    free_double_matrix(A_x_{j});\n")
        content += (f"    free_double_matrix(B_x_{j});\n")
        content += (f"    free_double_matrix(C_x_{j});\n")
    content += """\
    free_double_matrix(m);
    free_double_matrix(S);
    free_double_matrix(T);
    return 0;
}
"""
    with open("fmm_3x3.c", "w") as f:
        f.write(content)
    return

generate_fmm_3x3_header()
generate_fmm_3x3_source()
