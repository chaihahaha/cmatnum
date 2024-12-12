import os
import re
import sympy as sp
from collections import defaultdict
from sympy.parsing.sympy_parser import parse_expr
import pickle

# Define the base directory for the generated files
base_dir = "generated_files"
os.makedirs(base_dir, exist_ok=True)


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

# Function to generate the header file content
def generate_packmats_file(base_dir):
    content = """\
#ifndef PACK_MATS_H
#define PACK_MATS_H
#include "cmat.h"
struct pack_mats_32x32 {
"""
    for i in range(1,33):
        for j in range(1,33):
            content+=f"    double_cmat A_{i}_{j};\n"
            content+=f"    double_cmat B_{i}_{j};\n"
            content+=f"    double_cmat C_{i}_{j};\n"

    with open("A_eval_order.pickle", "rb") as f:
        A_eval_order = pickle.load(f)
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = list(set([i[0] for i in Axx_eval]))
    N_Axx_eval = len(Axx_eval)

    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i in Axx_names:
        content+=f"    double_cmat {i};\n"
    for i,j in B_replacements:
        content+=f"    double_cmat {i};\n"

    content +="""
};
typedef struct pack_mats_32x32 pack_mats_32x32;
#endif
"""
    filename = f"{base_dir}/pack_mats.h"
    with open(filename, "w") as f:
        f.write(content)
    return 

def generate_fm_header_files(base_dir):
    for fm_index in range(1, 15137):
        content = f"""\
#ifndef FM_{fm_index}_H
#define FM_{fm_index}_H

int fm_{fm_index}(double_cmat m, pack_mats_32x32 bmats);
#endif
"""
        with open(f"{base_dir}/fm_{fm_index}.h", "w") as f:
            f.write(content)
    return content


# Function to generate the source file content
def generate_fm_source_files(base_dir):
    m_terms = [sp.Symbol(f"m_{i}") for i in range(1, 15137)]
    d_mterms = {str(i): i for i in m_terms}

    with open("C.txt", "r") as f:
        Cs = f.read()
    m_to_C = get_m_to_C_inc_mapping(Cs, d_mterms)

    with open("A_reduced_exprs.pickle", "rb") as f:
        A_reduced_exprs = pickle.load(f)
    with open("B_reduced_exprs.pickle", "rb") as f:
        B_reduced_exprs = pickle.load(f)

    for fm_index_1 in range(15136):
        fm_index = fm_index_1 + 1
        expr_A = A_reduced_exprs[fm_index_1]
        expr_B = B_reduced_exprs[fm_index_1]

        content = f"""\
#include "stdafx.h"
#include "fm_{fm_index}.h"

inline int fm_{fm_index}(double_cmat m, pack_mats_32x32 bmats) {{
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {{BL, BL}}, &tmp0);
    create_double_matrix(pairint {{BL, BL}}, &tmp1);
"""
        
        sum_expr_A = sp.ccode(expr_A)
        pattern = r"([+-]?\s*\d*)\s*\*?\s*(m_\d+)" 
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Axx\d+)")
        # TODO: should reset tmp Axx to zero
        # TODO: should cautious tmp Axx add to itself, separate adding other vars and add to self
        sum_expr_B = sp.ccode(expr_B)
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bx\d+)")

        n_A_mats = len(A_names)
        n_B_mats = len(B_names)

        content += f"    int n_A_mats = {n_A_mats};\n"
        content += f"    double_cmat A_mats[{n_A_mats}] = {{"
        for name in A_names:
            content += f"bmats.{name}, "
        content += "};\n"
        content += f"    double A_coeffs[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}, "
        content += "};\n"

        content += f"    int n_B_mats = {n_B_mats};\n"
        content += f"    double_cmat B_mats[{n_B_mats}] = {{"
        for name in B_names:
            content += f"bmats.{name}, "
        content += "};\n"
        content += f"    double B_coeffs[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        content += "    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);\n"
        content += "    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);\n"
        content += "    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);\n"

        content += """\
    matmul_double_blas(m, tmp0, tmp1);
"""
        m_term = f"m_{fm_index}"
        for Ci, coefficient in m_to_C[m_term]:
            content += f"    cblas_daxpy(BL*BL, {coefficient}, &m.data[0][0], 1, &bmats.{Ci}.data[0][0], 1);\n"
        content += """\
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
"""
        with open(f"{base_dir}/fm_{fm_index}.c", "w") as f:
            f.write(content)
    return 


def generate_fmm_32x32_header():
    content = """\
#ifndef FMM_32x32_H
#define FMM_32x32_H

#include <stdio.h>
#include <stdlib.h>
#include "cmat.h"
#include "matmul.h"
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
    for fm_index in range(1, 15137):
        content += (f"#include \"fm_{fm_index}.h\"\n")
    with open("A_eval_order.pickle", "rb") as f:
        A_eval_order = pickle.load(f)
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)

    # extract the Axx evals that has to be called in separate functions
    # mA123 evals are called in fm_123
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = list(set([i[0] for i in Axx_eval]))
    N_Axx_eval = len(Axx_eval)
    for i in range(N_Axx_eval):
        content += (f"#include \"fAxxeval{i}.h\"\n")

    for i,j in B_replacements:
        idf = str(i)
        content += (f"#include \"f{idf}.h\"\n")
    content += """\
#include "stdafx.h"
#include "matmul.h"
#include "fmm_32x32.h"

int fmm_32x32(double_cmat C, double_cmat A, double_cmat B) {
    int height = A.shape[0];
    int width = A.shape[1];
    if (height <= 1024 || width <= 1024) {
        matmul_double_blas(C, A, B);
        return 0;
    }
    if (!(height % 32 == width % 32 && height % 32 == 0 && height / 32 == width / 32)) {
        //return matmul_double(C, A, B);
        return -1;
    }
    int N = height;
    int BL = N/32;
    int NS = BL*BL;
    double_cmat m;
    create_double_matrix(pairint {BL, BL}, &m);
"""

    content += ("    pack_mats_32x32 bmats;\n")
    for j in range(1,33):
        content += (f"    double_cmat A_x_{j};\n")
        content += (f"    double_cmat B_x_{j};\n")
        content += (f"    double_cmat C_x_{j};\n")
    for j in range(1,33):
        content += (f"    create_slice_double_matrix_contiguous(&A_x_{j}, A, pairint {{ 0, N }}, pairint {{ {(j-1)}*BL, {j}*BL }});\n")
        content += (f"    create_slice_double_matrix_contiguous(&B_x_{j}, B, pairint {{ 0, N }}, pairint {{ {(j-1)}*BL, {j}*BL }});\n")
        content += (f"    create_double_matrix(pairint {{ N, BL }}, &C_x_{j});\n")
    for i in range(1,33):
        for j in range(1,33):
            content += (f"    bmats.A_{i}_{j} = slice_double_matrix(A_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")
            content += (f"    bmats.B_{i}_{j} = slice_double_matrix(B_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")
            content += (f"    bmats.C_{i}_{j} = slice_double_matrix(C_x_{j}, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{0, BL}});\n")

    for i in Axx_names:
        content+=f"    create_double_matrix(pairint {{BL, BL}}, &bmats.{i});\n"
    for i,j in B_replacements:
        content+=f"    create_double_matrix(pairint {{BL, BL}}, &bmats.{i});\n"

    # generate func calls to fAxi, fBxi
    for i,j in B_replacements:
        idf = str(i)
        content += f"    f{idf}(bmats);\n"

    # generate func calls to fm_i
    cnt_Axx = 0
    for i in A_eval_order:
        var_name = i[0]
        expr = i[1]
        final_m_str = 'mA'
        temp_str = 'Axx'
        if final_m_str in var_name:
            content += f"    fm_{var_name.lstrip(final_m_str)}(m, bmats);\n"
        if temp_str in var_name:
            content += f"    fAxxeval{cnt_Axx}(bmats);\n"
            cnt_Axx += 1

    # copy C_x_j to C[:][j]
    for j in range(1,33):
        content += f"    assign_double_slice(C, C_x_{j}, pairint {{0, N}}, pairint {{ {(j-1)}*BL, {j}*BL }});\n"

    for i in range(1,33):
        for j in range(1,33):
            content += (f"    free_double_matrix(bmats.A_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.B_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.C_{i}_{j});\n")
    for j in range(1,33):
        content += (f"    free_double_matrix(A_x_{j});\n")
        content += (f"    free_double_matrix(B_x_{j});\n")
        content += (f"    free_double_matrix(C_x_{j});\n")
    for i in Axx_names:
        content+=f"    free_double_matrix(bmats.{i});\n"
    for i,j in B_replacements:
        content+=f"    free_double_matrix(bmats.{i});\n"
    content += """\
    free_double_matrix(m);
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

def generate_fAxxeval_source_files(base_dir):
    with open("A_eval_order.pickle", "rb") as f:
        A_eval_order = pickle.load(f)
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = list(set([i[0] for i in Axx_eval]))
    N_Axx_eval = len(Axx_eval)
    for i in range(N_Axx_eval):
        idf = Axx_eval[i][0]
        expr = Axx_eval[i][1]
        func_name = f'Axxeval{i}'
        sum_expr = sp.ccode(expr)
        content = f"""\
#include "stdafx.h"
#include "f{func_name}.h"

inline int f{func_name}(pack_mats_32x32 bmats) {{
    int BL = bmats.A_1_1.shape[0];
"""
        sum_expr_A = sum_expr
        A_names, A_coeffs = formula_to_matrices_coeffs_lists(sum_expr_A,  r"([+-]?\s*\d*)\s*\*?\s*(A_\d*_\d*|Axx\d+)")
        self_inds = []
        for i in range(len(A_names)):
            name = A_names[i]
            if idf == name:
                self_inds.append(i)
        assert len(self_inds) <=1
        if len(self_inds)==1:
            self_ind = self_inds[0]
            A_names_self = A_names.pop(self_ind)
            A_coeffs_self = A_coeffs.pop(self_ind)
            content += f"    cblas_dscal(BL*BL, {A_coeffs_self}, &bmats.{idf}.data[0][0], 1);\n"
        else:
            reset_var = f"bmats.{idf}"
            content+= f"    memset(&{reset_var}.data[0][0], 0, sizeof({reset_var}.data[0][0])*BL*BL);\n"

        n_A_mats = len(A_names)

        content += f"    int n_A_mats = {n_A_mats};\n"
        content += f"    double_cmat A_mats[{n_A_mats}] = {{"
        for name in A_names:
            content += f"bmats.{name}, "
        content += "};\n"
        content += f"    double A_coeffs[{n_A_mats}] = {{"
        for c in A_coeffs:
            content += f"{c}, "
        content += "};\n"

        content += f"    matlincomb_double_contiguous(bmats.{idf}, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);\n"
        content += """
    return 0;
}
"""
        with open(f"{base_dir}/f{func_name}.c", "w") as f:
            f.write(content)
    return

def generate_fAxxeval_header_files(base_dir):
    with open("A_eval_order.pickle", "rb") as f:
        A_eval_order = pickle.load(f)
    Axx_eval = [i for i in A_eval_order if 'Axx' in i[0]]
    Axx_names = list(set([i[0] for i in Axx_eval]))
    N_Axx_eval = len(Axx_eval)
    for i in range(N_Axx_eval):
        idf = Axx_eval[i][0]
        expr = Axx_eval[i][1]
        func_name = f'Axxeval{i}'
        func_name_upper = func_name.upper()
        content = f"""\
#ifndef F{func_name_upper}_H
#define F{func_name_upper}_H

int f{func_name}(pack_mats_32x32 bmats);
#endif
"""
        with open(f"{base_dir}/f{func_name}.h", "w") as f:
            f.write(content)
    return

def generate_fBx_source_files(base_dir):
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in B_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        sum_expr = sp.ccode(j)
        content = f"""\
#include "stdafx.h"
#include "f{idf}.h"

inline int f{idf}(pack_mats_32x32 bmats) {{
    int BL = bmats.B_1_1.shape[0];
"""
        sum_expr_B = sum_expr
        pattern = r"([+-]?\s*\d*)\s*\*?\s*(m_\d+)" 
        B_names, B_coeffs = formula_to_matrices_coeffs_lists(sum_expr_B,  r"([+-]?\s*\d*)\s*\*?\s*(B_\d*_\d*|Bx\d+)")

        n_B_mats = len(B_names)

        content += f"    int n_B_mats = {n_B_mats};\n"
        content += f"    double_cmat B_mats[{n_B_mats}] = {{"
        for name in B_names:
            content += f"bmats.{name}, "
        content += "};\n"
        content += f"    double B_coeffs[{n_B_mats}] = {{"
        for c in B_coeffs:
            content += f"{c}, "
        content += "};\n"

        reset_var = f"bmats.{idf}"
        content+= f"memset(&{reset_var}.data[0][0], 0, sizeof({reset_var}.data[0][0])*{reset_var}.shape[0]*{reset_var}.shape[1]);\n"

        content += f"    matlincomb_double_contiguous(bmats.{idf}, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);\n"
        content += """
    return 0;
}
"""
        with open(f"{base_dir}/f{idf}.c", "w") as f:
            f.write(content)
    return

def generate_fBx_header_files(base_dir):
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in B_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        content = f"""\
#ifndef F{idf_upper}_H
#define F{idf_upper}_H

int f{idf}(pack_mats_32x32 bmats);
#endif
"""
        with open(f"{base_dir}/f{idf}.h", "w") as f:
            f.write(content)
    return

generate_fmm_32x32_header()
generate_fmm_32x32_source()
generate_fm_source_files(base_dir)
generate_packmats_file(base_dir)
generate_fm_header_files(base_dir)
generate_fAxxeval_source_files(base_dir)
generate_fAxxeval_header_files(base_dir)
generate_fBx_source_files(base_dir)
generate_fBx_header_files(base_dir)
