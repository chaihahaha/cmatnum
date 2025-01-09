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
def generate_fm_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements):
    m_terms = [sp.Symbol(f"m_{i}") for i in range(1, 15137)]
    d_mterms = {str(i): i for i in m_terms}

    with open("C_32x32.txt", "r") as f:
        Cs = f.read()
    m_to_C = get_m_to_C_inc_mapping(Cs, d_mterms)

    fmi2code = dict()

    for fm_index_1 in range(15136):
        fm_index = fm_index_1 + 1
        expr_A = A_reduced_exprs[fm_index_1]
        expr_B = B_reduced_exprs[fm_index_1]

        content = ""
        
        sum_expr_A = sp.ccode(expr_A)
        pattern = r"([+-]?\s*\d*)\s*\*?\s*(m_\d+)" 
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Axx\d+)")
        sum_expr_B = sp.ccode(expr_B)
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bx\d+)")

        n_A_mats = len(A_names)
        n_B_mats = len(B_names)


        content += f"    static const double A_coeffs_{fm_index}[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}*dnum17, "
        content += "};\n"

        for idx, name in enumerate(A_names):
            content += f"    marr[{idx}]={name};\n"
        #content += f"    matlincomb_double_contiguous(tmp0, {n_A_mats}, (double_cmat*)marr, (int8_t*)A_coeffs_{fm_index});\n"
        content += f"""
    for (shape_uint i = 0; i < {n_A_mats}; i++) {{
        cblas_daxpy(NS, A_coeffs_{fm_index}[i], marr[i].data[0], 1, tmp0.data[0], 1);
    }}
"""

        content += f"    static const int8_t B_coeffs_{fm_index}[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(B_names):
            content += f"    marr[{idx}]={name};\n"
        #content += f"    matlincomb_double_contiguous(tmp1, {n_B_mats}, (double_cmat*)marr, (int8_t*)B_coeffs_{fm_index});\n"
        content += f"""
    for (shape_uint i = 0; i < {n_B_mats}; i++) {{
        cblas_daxpy(NS, B_coeffs_{fm_index}[i], marr[i].data[0], 1, tmp1.data[0], 1);
    }}
"""

        #content += "    cblas_dscal(NS, dnum17, &tmp0.data[0][0], 1);\n"

        content += """\
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    BL, BL, BL,
                    1.0, tmp0.data[0], BL,
                    tmp1.data[0], BL,
                    0.0, m.data[0], BL);
"""
        m_term = f"m_{fm_index}"
        for Ci, coefficient in m_to_C[m_term]:
            content += f"    cblas_daxpy(NS, {coefficient}, &m.data[0][0], 1, &{Ci}.data[0][0], 1);\n"
        content += """\
    for(shape_uint arenai=0; arenai<NS; arenai++) tmp0.arena[arenai] = 0;
    for(shape_uint arenai=0; arenai<NS; arenai++) tmp1.arena[arenai] = 0;
"""
        fmi2code[str(fm_index)] = content
    return fmi2code


def generate_fmm_32x32_header():
    content = """\
#ifndef FMM_32x32_H
#define FMM_32x32_H

#include <stdio.h>
#include <stdlib.h>
#include "cmat.h"
"""
    content += """\
int fmm_32x32(double_cmat C, double_cmat A, double_cmat B);

#endif
"""
    with open("fmm_32x32.h", "w") as f:
        f.write(content)
    return

def generate_fmm_32x32_source():
    content = ""
    with open("A_eval_order_32x32.pickle", "rb") as f:
        A_eval_order = pickle.load(f)
    with open("A_reduced_exprs_32x32.pickle", "rb") as f:
        A_reduced_exprs = pickle.load(f)
    with open("B_replacements_32x32.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    with open("B_reduced_exprs_32x32.pickle", "rb") as f:
        B_reduced_exprs = pickle.load(f)

    fmi2code = generate_fm_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements)
    Axxi2code = generate_fAxxeval_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements)
    Bxi2code = generate_fBx_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements)

    # extract the Axx evals that has to be called in separate functions
    # mA123 evals are called in fm_123
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = sorted(list(set([i[0] for i in Axx_eval])))
    N_Axx_eval = len(Axx_eval)

    content += """\
#include "cmat.h"
#include "fmm_32x32.h"

int fmm_32x32(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint height = A.shape[0];
    shape_uint width = A.shape[1];
    if (height <= 1024 || width <= 1024) {
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A.shape[1],
                    1.0, A.data[0], A.arena_shape[1],
                    B.data[0], B.arena_shape[1],
                    0.0, C.data[0], C.arena_shape[1]);
        return 0;
    }
    if (!(height % 32 == width % 32 && height % 32 == 0 && height / 32 == width / 32)) {
        //return matmul_double(C, A, B);
        return -1;
    }
    shape_uint N = height;
    shape_uint BL = N/32;
    shape_uint NS = BL*BL;
    static const double dnum17 = 1/17.0;
    double_cmat m;
    create_double_matrix(pairuint {BL, BL}, &m);
    double_cmat tmp0, tmp1;
    create_double_matrix(pairuint {BL, BL}, &tmp0);
    create_double_matrix(pairuint {BL, BL}, &tmp1);
    double_cmat marr[60] = {NULL};
"""

    for j in range(1,33):
        content += (f"    double_cmat A_x_{j};\n")
        content += (f"    double_cmat B_x_{j};\n")
        content += (f"    double_cmat C_x_{j};\n")
    for j in range(1,33):
        content += (f"    create_slice_double_matrix_contiguous(&A_x_{j}, A, pairint {{ 0, N }}, pairint {{ {(j-1)}*BL, {j}*BL }});\n")
        content += (f"    create_slice_double_matrix_contiguous(&B_x_{j}, B, pairint {{ 0, N }}, pairint {{ {(j-1)}*BL, {j}*BL }});\n")
        content += (f"    create_double_matrix(pairuint {{ N, BL }}, &C_x_{j});\n")
    for i in range(1,33):
        for j in range(1,33):
            content += (f"    double_cmat A_{i}_{j} = slice_double_matrix(A_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")
            content += (f"    double_cmat B_{i}_{j} = slice_double_matrix(B_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")
            content += (f"    double_cmat C_{i}_{j} = slice_double_matrix(C_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")

    for i in Axx_names:
        content+=f"    double_cmat {i};\n"
    for i,j in B_replacements:
        content+=f"    double_cmat {i};\n"

    for i in Axx_names:
        content+=f"    create_double_matrix(pairuint {{BL, BL}}, &{i});\n"
    for i,j in B_replacements:
        content+=f"    create_double_matrix(pairuint {{BL, BL}}, &{i});\n"

    # generate func calls to fAxi, fBxi
    for i,j in B_replacements:
        idf = str(i)
        content += Bxi2code[idf]

    # generate func calls to fm_i
    cnt_Axx = 0
    for i in A_eval_order:
        var_name = i[0]
        expr = i[1]
        final_m_str = 'mA'
        temp_str = 'Axx'
        if final_m_str in var_name:
            content += fmi2code[var_name.lstrip(final_m_str)]
        if temp_str in var_name:
            content += Axxi2code[cnt_Axx]
            cnt_Axx += 1

    # copy C_x_j to C[:][j]
    for j in range(1,33):
        content += f"    assign_double_slice(C, C_x_{j}, pairint {{0, N}}, pairint {{ {(j-1)}*BL, {j}*BL }});\n"

    for i in range(1,33):
        for j in range(1,33):
            content += (f"    free_double_matrix(A_{i}_{j});\n")
            content += (f"    free_double_matrix(B_{i}_{j});\n")
            content += (f"    free_double_matrix(C_{i}_{j});\n")
    for j in range(1,33):
        content += (f"    free_double_matrix(A_x_{j});\n")
        content += (f"    free_double_matrix(B_x_{j});\n")
        content += (f"    free_double_matrix(C_x_{j});\n")
    for i in Axx_names:
        content+=f"    free_double_matrix({i});\n"
    for i,j in B_replacements:
        content+=f"    free_double_matrix({i});\n"
    content += """\
    free_double_matrix(m);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
"""
    with open("fmm_32x32.c", "w") as f:
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

def generate_fAxxeval_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements):
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = list(set([i[0] for i in Axx_eval]))
    N_Axx_eval = len(Axx_eval)
    Axxi2code = dict()
    idfappear = set()
    for i in range(N_Axx_eval):
        idf = Axx_eval[i][0]
        expr = Axx_eval[i][1]
        func_name = f'Axxeval{i}'
        sum_expr = sp.ccode(expr)
        sum_expr_A = sum_expr
        content = ""
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Axx\d+)")
        self_inds = []
        for j in range(len(A_names)):
            name = A_names[j]
            if idf == name:
                self_inds.append(j)
        assert len(self_inds) <=1
        if len(self_inds)==1:
            self_ind = self_inds[0]
            A_names_self = A_names.pop(self_ind)
            A_coeffs_self = A_coeffs.pop(self_ind)
            content += f"    cblas_dscal(NS, {A_coeffs_self}, &{idf}.data[0][0], 1);\n"
        else:
            reset_var = f"{idf}"
            if reset_var not in idfappear:
                idfappear.add(reset_var)
            else:
                content+= f"    for(shape_uint arenai=0; arenai<NS; arenai++) {reset_var}.arena[arenai] = 0;\n"

        n_A_mats = len(A_names)

        content += f"    static const int8_t A_coeffs_{func_name}[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(A_names):
            content += f"    marr[{idx}]={name};\n"
        #content += f"    matlincomb_double_contiguous({idf}, {n_A_mats}, (double_cmat*)marr,  (int8_t*)A_coeffs_{func_name});\n"
        content += f"""
    for (shape_uint i = 0; i < {n_A_mats}; i++) {{
        cblas_daxpy(NS, A_coeffs_{func_name}[i], marr[i].data[0], 1, {idf}.data[0], 1);
    }}
"""
        Axxi2code[i] = content
    return Axxi2code


def generate_fBx_source_files(A_eval_order, A_reduced_exprs, B_reduced_exprs, B_replacements):
    Bxi2code = dict()
    for i,j in B_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        sum_expr = sp.ccode(j)
        content = ""
        sum_expr_B = sum_expr
        pattern = r"([+-]?\s*\d*)\s*\*?\s*(m_\d+)" 
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bx\d+)")

        n_B_mats = len(B_names)


        reset_var = f"{idf}"

        content += f"    static const int8_t B_coeffs_{idf}[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        for idx, name in enumerate(B_names):
            content += f"    marr[{idx}]={name};\n"
        #content += f"    matlincomb_double_contiguous({idf}, {n_B_mats}, (double_cmat*)marr,  (int8_t*)B_coeffs_{idf});\n"
        content += f"""
    for (shape_uint i = 0; i < {n_B_mats}; i++) {{
        cblas_daxpy(NS, B_coeffs_{idf}[i], marr[i].data[0], 1, {idf}.data[0], 1);
    }}
"""
        Bxi2code[idf] = content
    return Bxi2code

generate_fmm_32x32_source()
generate_fmm_32x32_header()
