import sympy as sp
import numpy as np
import pickle

# check precison of Smirnov 3x3x3 rank 20 approx matmul

threshold = 1e-3

x = 1e-2
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
    if (height <= 1200 || width <= 1200 || !(height % 3 == width % 3 && height % 3 == 0 && height / 3 == width / 3)) {
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
    double_cmat m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19;
    double_cmat S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15,S16,S17,S18,S19;
    double_cmat T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19;
    create_double_matrix(pairuint {BL, BL}, &m0);
    create_double_matrix(pairuint {BL, BL}, &m1);
    create_double_matrix(pairuint {BL, BL}, &m2);
    create_double_matrix(pairuint {BL, BL}, &m3);
    create_double_matrix(pairuint {BL, BL}, &m4);
    create_double_matrix(pairuint {BL, BL}, &m5);
    create_double_matrix(pairuint {BL, BL}, &m6);
    create_double_matrix(pairuint {BL, BL}, &m7);
    create_double_matrix(pairuint {BL, BL}, &m8);
    create_double_matrix(pairuint {BL, BL}, &m9);
    create_double_matrix(pairuint {BL, BL}, &m10);
    create_double_matrix(pairuint {BL, BL}, &m11);
    create_double_matrix(pairuint {BL, BL}, &m12);
    create_double_matrix(pairuint {BL, BL}, &m13);
    create_double_matrix(pairuint {BL, BL}, &m14);
    create_double_matrix(pairuint {BL, BL}, &m15);
    create_double_matrix(pairuint {BL, BL}, &m16);
    create_double_matrix(pairuint {BL, BL}, &m17);
    create_double_matrix(pairuint {BL, BL}, &m18);
    create_double_matrix(pairuint {BL, BL}, &m19);
    create_double_matrix(pairuint {BL, BL}, &S0);
    create_double_matrix(pairuint {BL, BL}, &S1);
    create_double_matrix(pairuint {BL, BL}, &S2);
    create_double_matrix(pairuint {BL, BL}, &S3);
    create_double_matrix(pairuint {BL, BL}, &S4);
    create_double_matrix(pairuint {BL, BL}, &S5);
    create_double_matrix(pairuint {BL, BL}, &S6);
    create_double_matrix(pairuint {BL, BL}, &S7);
    create_double_matrix(pairuint {BL, BL}, &S8);
    create_double_matrix(pairuint {BL, BL}, &S9);
    create_double_matrix(pairuint {BL, BL}, &S10);
    create_double_matrix(pairuint {BL, BL}, &S11);
    create_double_matrix(pairuint {BL, BL}, &S12);
    create_double_matrix(pairuint {BL, BL}, &S13);
    create_double_matrix(pairuint {BL, BL}, &S14);
    create_double_matrix(pairuint {BL, BL}, &S15);
    create_double_matrix(pairuint {BL, BL}, &S16);
    create_double_matrix(pairuint {BL, BL}, &S17);
    create_double_matrix(pairuint {BL, BL}, &S18);
    create_double_matrix(pairuint {BL, BL}, &S19);
    create_double_matrix(pairuint {BL, BL}, &T0);
    create_double_matrix(pairuint {BL, BL}, &T1);
    create_double_matrix(pairuint {BL, BL}, &T2);
    create_double_matrix(pairuint {BL, BL}, &T3);
    create_double_matrix(pairuint {BL, BL}, &T4);
    create_double_matrix(pairuint {BL, BL}, &T5);
    create_double_matrix(pairuint {BL, BL}, &T6);
    create_double_matrix(pairuint {BL, BL}, &T7);
    create_double_matrix(pairuint {BL, BL}, &T8);
    create_double_matrix(pairuint {BL, BL}, &T9);
    create_double_matrix(pairuint {BL, BL}, &T10);
    create_double_matrix(pairuint {BL, BL}, &T11);
    create_double_matrix(pairuint {BL, BL}, &T12);
    create_double_matrix(pairuint {BL, BL}, &T13);
    create_double_matrix(pairuint {BL, BL}, &T14);
    create_double_matrix(pairuint {BL, BL}, &T15);
    create_double_matrix(pairuint {BL, BL}, &T16);
    create_double_matrix(pairuint {BL, BL}, &T17);
    create_double_matrix(pairuint {BL, BL}, &T18);
    create_double_matrix(pairuint {BL, BL}, &T19);
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
            coeff = float(coeff)
            content += f"""
    cblas_daxpy(NS, {coeff}, {var}.data[0], 1, S{sidx}.data[0], 1);
"""
    for tidx in range(20):
        if T_exprs[tidx].is_Mul:
            args = [T_exprs[tidx]]
        else:
            args = T_exprs[tidx].args
        for T_arg in args:
            var = list(T_arg.free_symbols)[0]
            coeff = T_arg.coeff(var)
            var = str(var)
            coeff = float(coeff)
            content += f"""
    cblas_daxpy(NS, {coeff}, {var}.data[0], 1, T{tidx}.data[0], 1);
"""
    for midx in range(20):
        content += f"""\
    fmm_3x3(m{midx}, S{midx}, T{midx});
"""
#        content += f"""\
#    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
#                BL, BL, BL,
#                1.0, S{midx}.data[0], BL,
#                T{midx}.data[0], BL,
#                0.0, m{midx}.data[0], BL);
#"""
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
                coeff = float(coeff)
                content += f"    cblas_daxpy(NS, {coeff}, &{var}.data[0][0], 1, &C_{i}_{j}.data[0][0], 1);\n"
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
    free_double_matrix(m0);
    free_double_matrix(m1);
    free_double_matrix(m2);
    free_double_matrix(m3);
    free_double_matrix(m4);
    free_double_matrix(m5);
    free_double_matrix(m6);
    free_double_matrix(m7);
    free_double_matrix(m8);
    free_double_matrix(m9);
    free_double_matrix(m10);
    free_double_matrix(m11);
    free_double_matrix(m12);
    free_double_matrix(m13);
    free_double_matrix(m14);
    free_double_matrix(m15);
    free_double_matrix(m16);
    free_double_matrix(m17);
    free_double_matrix(m18);
    free_double_matrix(m19);
    free_double_matrix(S0);
    free_double_matrix(S1);
    free_double_matrix(S2);
    free_double_matrix(S3);
    free_double_matrix(S4);
    free_double_matrix(S5);
    free_double_matrix(S6);
    free_double_matrix(S7);
    free_double_matrix(S8);
    free_double_matrix(S9);
    free_double_matrix(S10);
    free_double_matrix(S11);
    free_double_matrix(S12);
    free_double_matrix(S13);
    free_double_matrix(S14);
    free_double_matrix(S15);
    free_double_matrix(S16);
    free_double_matrix(S17);
    free_double_matrix(S18);
    free_double_matrix(S19);
    free_double_matrix(T0);
    free_double_matrix(T1);
    free_double_matrix(T2);
    free_double_matrix(T3);
    free_double_matrix(T4);
    free_double_matrix(T5);
    free_double_matrix(T6);
    free_double_matrix(T7);
    free_double_matrix(T8);
    free_double_matrix(T9);
    free_double_matrix(T10);
    free_double_matrix(T11);
    free_double_matrix(T12);
    free_double_matrix(T13);
    free_double_matrix(T14);
    free_double_matrix(T15);
    free_double_matrix(T16);
    free_double_matrix(T17);
    free_double_matrix(T18);
    free_double_matrix(T19);
    return 0;
}
"""
    with open("fmm_3x3.c", "w") as f:
        f.write(content)
    return

generate_fmm_3x3_header()
generate_fmm_3x3_source()
