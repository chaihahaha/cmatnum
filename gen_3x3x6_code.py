import os
import re
import sympy as sp
from collections import defaultdict
from sympy.parsing.sympy_parser import parse_expr
import pickle


def formula_to_matrices_coeffs_lists(formula, pattern):
    # Regular expression to match terms with optional coefficients and matrix names
    
    # Lists to store extracted matrix names and coefficients
    matrices = []
    coefficients = []
    
    # Find all matches in the formula
    matches = re.findall(pattern, formula)
    
    # Process each match
    for coeff, matrix in matches:
        # Convert the coefficient to an integer; handle cases where it's empty or just a sign
        coeff = coeff.replace(" ", "")
        if coeff == '' or coeff == '+':
            coeff = 1
        elif coeff == '-':
            coeff = -1
        else:
            coeff = int(coeff)
    
        # Append matrix name and coefficient to lists
        matrices.append(matrix)
        coefficients.append(coeff)
    return matrices, coefficients


# Function to generate the source file content
def generate_fm_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements):
    m_terms = [sp.Symbol(f"m_{i}") for i in range(1, 41)]
    d_mterms = {str(i): i for i in m_terms}

    with open("C_3x3x6.txt", "r") as f:
        Cs = f.read()
    m_to_C = get_m_to_C_inc_mapping(Cs, d_mterms)

    fmi2code = dict()

    for fm_index_1 in range(40):
        fm_index = fm_index_1 + 1
        expr_A = A_reduced_exprs[fm_index_1]
        expr_B = B_reduced_exprs[fm_index_1]

        content = ""
        
        sum_expr_B = sp.ccode(expr_B)
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bxx\d+)")
        sum_expr_A = sp.ccode(expr_A)
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Ax\d+)")

        n_A_mats = len(A_names)
        n_B_mats = len(B_names)


        content += f"    static const int8_t A_coeffs_{fm_index}[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(A_names):
            content += f"    marr[{idx}]={name};\n"
        content += f"    matlincomb_double_contiguous(tmp0, {n_A_mats}, (double_cmat*)marr, (int8_t*)A_coeffs_{fm_index});\n"

        content += f"    static const int8_t B_coeffs_{fm_index}[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(B_names):
            content += f"    marr[{idx}]={name};\n"
        content += f"    matlincomb_double_contiguous(tmp1, {n_B_mats}, (double_cmat*)marr, (int8_t*)B_coeffs_{fm_index});\n"

        content += "    cblas_dscal(NSB, dnum8, &tmp1.data[0][0], 1);\n"

        content += """\
    matmul_double_blas(m, tmp0, tmp1);
"""
        m_term = f"m_{fm_index}"
        for Ci, coefficient in m_to_C[m_term]:
            content += f"    cblas_daxpy(NSC, {coefficient}.0, &m.data[0][0], 1, &{Ci}.data[0][0], 1);\n"
        content += """\
    for(shape_uint arenai=0; arenai<NSA; arenai++) tmp0.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NSB; arenai++) tmp1.arena[arenai] = 0;
"""
        fmi2code[str(fm_index)] = content
    return fmi2code


def generate_fmm_3x3x6_header():
    content = """\
#ifndef FMM_3x3x6_H
#define FMM_3x3x6_H

#include <stdio.h>
#include <stdlib.h>
#include "cmat.h"
#include "matmul.h"
"""
    content += """\
int fmm_3x3x6(double_cmat C, double_cmat A, double_cmat B);

#endif
"""
    with open("fmm_3x3x6.h", "w") as f:
        f.write(content)
    return

def generate_fmm_3x3x6_source():
    content = ""
    with open("B_eval_order_3x3x6.pickle", "rb") as f:
        B_eval_order = pickle.load(f)
    with open("B_reduced_exprs_3x3x6.pickle", "rb") as f:
        B_reduced_exprs = pickle.load(f)
    with open("A_replacements_3x3x6.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    with open("A_reduced_exprs_3x3x6.pickle", "rb") as f:
        A_reduced_exprs = pickle.load(f)

    fmi2code = generate_fm_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements)
    Bxxi2code = generate_fBxxeval_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements)
    Axi2code = generate_fAx_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements)

    # extract the Bxx evals that has to be called in separate functions
    # mA123 evals are called in fm_123
    Bxx_eval = [i for i in B_eval_order if 'Bxx' in i[0]]
    Bxx_names = sorted(list(set([i[0] for i in Bxx_eval])))
    N_Bxx_eval = len(Bxx_eval)

    content += """\
#include "cmat.h"
#include "matmul.h"
#include "fmm_3x3x6.h"

int fmm_3x3x6(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint A_height = A.shape[0];
    shape_uint A_width = A.shape[1];
    shape_uint B_height = B.shape[0];
    shape_uint B_width = B.shape[1];
    shape_uint C_height = A.shape[0];
    shape_uint C_width = B.shape[1];
    if (A_height <= 1 || A_width <= 1) {
        matmul_double_blas(C, A, B);
        return 0;
    }
    shape_uint BLHA = A_height/3;
    shape_uint BLWA = A_width/3;
    shape_uint NSA = BLHA * BLWA;
    shape_uint BLHB = B_height/3;
    shape_uint BLWB = B_width/6;
    shape_uint NSB = BLHB * BLWB;
    shape_uint BLHC = A_height/3;
    shape_uint BLWC = B_width/6;
    shape_uint NSC = BLHC * BLWC;
    if (!(A_height % 3 == 0 && A_width % 3 == 0 && B_height % 3 == 0 && B_width % 6 == 0 && BLWA == BLHB)) {
        //return matmul_double(C, A, B);
        return -1;
    }
    double dnum8 = 1/8.0;
    double_cmat m;
    create_double_matrix(pairint {BLHC, BLWC}, &m);
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BLHA, BLWA}, &tmp0);
    create_double_matrix(pairint {BLHB, BLWB}, &tmp1);
    double_cmat marr[60] = {NULL};
"""

    for j in range(1,4):
        content += (f"    double_cmat A_x_{j};\n")
    for j in range(1,7):
        content += (f"    double_cmat B_x_{j};\n")
        content += (f"    double_cmat C_x_{j};\n")
    for j in range(1,4):
        content += (f"    create_slice_double_matrix_contiguous(&A_x_{j}, A, pairint {{ 0, A_height }}, pairint {{ {(j-1)}*BLWA, {j}*BLWA }});\n")
    for j in range(1,7):
        content += (f"    create_slice_double_matrix_contiguous(&B_x_{j}, B, pairint {{ 0, B_height }}, pairint {{ {(j-1)}*BLWB, {j}*BLWB }});\n")
    for j in range(1,7):
        content += (f"    create_double_matrix(pairint {{ C_height, BLWC }}, &C_x_{j});\n")
    for i in range(1,4):
        for j in range(1,4):
            content += (f"    double_cmat A_{i}_{j} = slice_double_matrix(A_x_{j}, pairint {{{(i-1)}*BLHA, {i}*BLWA}}, pairint {{0, BLWA}});\n")
    for i in range(1,4):
        for j in range(1,7):
            content += (f"    double_cmat B_{i}_{j} = slice_double_matrix(B_x_{j}, pairint {{{(i-1)}*BLHB, {i}*BLWB}}, pairint {{0, BLWB}});\n")
            content += (f"    double_cmat C_{i}_{j} = slice_double_matrix(C_x_{j}, pairint {{{(i-1)}*BLHC, {i}*BLWC}}, pairint {{0, BLWC}});\n")

    for i in Bxx_names:
        content+=f"    double_cmat {i};\n"
    for i,j in A_replacements:
        content+=f"    double_cmat {i};\n"

    for i in Bxx_names:
        content+=f"    create_double_matrix(pairint {{BLHB, BLWB}}, &{i});\n"
    for i,j in A_replacements:
        content+=f"    create_double_matrix(pairint {{BLHA, BLWA}}, &{i});\n"

    # generate func calls to fAxi, fBxi
    for i,j in A_replacements:
        idf = str(i)
        content += Axi2code[idf]

    # generate func calls to fm_i
    cnt_Bxx = 0
    for i in B_eval_order:
        var_name = i[0]
        expr = i[1]
        final_m_str = 'mB'
        temp_str = 'Bxx'
        if final_m_str in var_name:
            content += fmi2code[var_name.lstrip(final_m_str)]
        if temp_str in var_name:
            content += Bxxi2code[cnt_Bxx]
            cnt_Bxx += 1

    # copy C_x_j to C[:][j]
    for j in range(1,7):
        content += f"    assign_double_slice(C, C_x_{j}, pairint {{0, C_height}}, pairint {{ {(j-1)}*BLHC, {j}*BLWC }});\n"

    for i in range(1,4):
        for j in range(1,4):
            content += (f"    free_double_matrix(A_{i}_{j});\n")
    for i in range(1,4):
        for j in range(1,7):
            content += (f"    free_double_matrix(B_{i}_{j});\n")
            content += (f"    free_double_matrix(C_{i}_{j});\n")
    for j in range(1,4):
        content += (f"    free_double_matrix(A_x_{j});\n")
    for j in range(1,7):
        content += (f"    free_double_matrix(B_x_{j});\n")
        content += (f"    free_double_matrix(C_x_{j});\n")
    for i in Bxx_names:
        content+=f"    free_double_matrix({i});\n"
    for i,j in A_replacements:
        content+=f"    free_double_matrix({i});\n"
    content += """\
    free_double_matrix(m);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
"""
    with open("fmm_3x3x6.c", "w") as f:
        f.write(content)
    return


def get_m_to_C_inc_mapping(C_formulas, d_mterms):
    m_to_C = defaultdict(list)
    pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(m_\d+)"
    for line in C_formulas.split("\n"):
        if line:
            Ci, formula = line.split("=")
            formula = parse_expr(formula)
            formula = formula[0]
            matches = re.findall(pattern, str(formula))
            for mat in matches:
                m_term = d_mterms[mat[2]]
                m_to_C[str(m_term)].append((Ci, formula.coeff(m_term)))
    return m_to_C

def generate_fBxxeval_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements):
    Bxx_eval = [i for i in B_eval_order if 'Bxx' in i[0]]
    Bxx_names = list(set([i[0] for i in Bxx_eval]))
    N_Bxx_eval = len(Bxx_eval)
    Bxxi2code = dict()
    idfappear = set()
    for i in range(N_Bxx_eval):
        idf = Bxx_eval[i][0]
        expr = Bxx_eval[i][1]
        func_name = f'Bxxeval{i}'
        sum_expr = sp.ccode(expr)
        sum_expr_B = sum_expr
        content = ""
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bxx\d+)")
        self_inds = []
        for j in range(len(B_names)):
            name = B_names[j]
            if idf == name:
                self_inds.append(j)
        assert len(self_inds) <=1
        if len(self_inds)==1:
            self_ind = self_inds[0]
            B_names_self = B_names.pop(self_ind)
            B_coeffs_self = B_coeffs.pop(self_ind)
            content += f"    cblas_dscal(NSB, {B_coeffs_self}, &{idf}.data[0][0], 1);\n"
        else:
            reset_var = f"{idf}"
            if reset_var not in idfappear:
                idfappear.add(reset_var)
            else:
                content+= f"    for(shape_uint arenai=0; arenai<NSB; arenai++) {reset_var}.arena[arenai] = 0;\n"

        n_B_mats = len(B_names)

        content += f"    static const int8_t B_coeffs_{func_name}[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(B_names):
            content += f"    marr[{idx}]={name};\n"
        content += f"    matlincomb_double_contiguous({idf}, {n_B_mats}, (double_cmat*)marr,  (int8_t*)B_coeffs_{func_name});\n"
        Bxxi2code[i] = content
    return Bxxi2code


def generate_fAx_source_files(B_eval_order, B_reduced_exprs, A_reduced_exprs, A_replacements):
    Axi2code = dict()
    for i,j in A_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        sum_expr = sp.ccode(j)
        content = ""
        sum_expr_A = sum_expr
        pattern = r"([+-]?\s*\d*)\s*\*?\s*(m_\d+)" 
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Ax\d+)")

        n_A_mats = len(A_names)


        reset_var = f"{idf}"

        content += f"    static const int8_t A_coeffs_{idf}[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(A_names):
            content += f"    marr[{idx}]={name};\n"
        content += f"    matlincomb_double_contiguous({idf}, {n_A_mats}, (double_cmat*)marr,  (int8_t*)A_coeffs_{idf});\n"
        Axi2code[idf] = content
    return Axi2code

generate_fmm_3x3x6_source()
generate_fmm_3x3x6_header()
