import os
import re
import sympy as sp
from collections import defaultdict
from sympy.parsing.sympy_parser import parse_expr
import pickle

# Define the base directory for the generated files
base_dir = "generated_files"
os.makedirs(base_dir, exist_ok=True)

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

    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in A_replacements:
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

#include "stdafx.h"
int fmm_32x32(double_cmat C, double_cmat A, double_cmat B);

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
#include "fm_{fm_index}.h"

inline int fm_{fm_index}(double_cmat m, pack_mats_32x32 bmats) {{
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {{BL, BL}}, &tmp0);
    create_double_matrix(pairint {{BL, BL}}, &tmp1);
"""
        
        sum_expr_A = sp.ccode(expr_A)
        sum_expr_A = re.sub(r'([A-Zx]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', sum_expr_A)
        sum_expr_A = re.sub(r'(Ax\d+)', r'bmats.\1.data[i][j]', sum_expr_A)
        sum_expr_B = sp.ccode(expr_B)
        sum_expr_B = re.sub(r'([A-Zx]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', sum_expr_B)
        sum_expr_B = re.sub(r'(Bx\d+)', r'bmats.\1.data[i][j]', sum_expr_B)

        content += f"""\
    for (int i=0; i<BL; i++) {{
        for (int j=0; j<BL; j++) {{
            tmp0.data[i][j] = {sum_expr_A};
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = {sum_expr_B};
        }}
    }}
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {{
        for (int j=0; j<BL; j++) {{
"""
        m_term = f"m_{fm_index}"
        for Ci, coefficient in m_to_C[m_term]:
            content += f"        bmats.{Ci}.data[i][j]+={coefficient} * m.data[i][j];\n"
        content += """\
        }
    }
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
#include "stdafx.h"
#include "matmul.h"
"""
    for fm_index in range(1, 15137):
        content += (f"#include \"fm_{fm_index}.h\"\n")
    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in A_replacements+B_replacements:
        idf = str(i)
        content += (f"#include \"f{idf}.h\"\n")
    content += """\
int fmm_32x32(double_cmat C, double_cmat A, double_cmat B);

#endif
"""
    with open("fmm_32x32.h", "w") as f:
        f.write(content)
    return

def generate_fmm_32x32_source():
    content = """\
#include "fmm_32x32.h"

int fmm_32x32(double_cmat C, double_cmat A, double_cmat B) {
    int height = A.shape[0];
    int width = A.shape[1];
    if (height <= 2048 || width <= 2048) {
        matmul_double_strassen_winograd(C, A, B);
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

    content += ("pack_mats_32x32 bmats;\n")
    for i in range(1,33):
        for j in range(1,33):
            content += (f"    bmats.A_{i}_{j} = slice_double_matrix(A, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            content += (f"    bmats.B_{i}_{j} = slice_double_matrix(B, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            content += (f"    bmats.C_{i}_{j} = slice_double_matrix(C, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")

    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in A_replacements:
        content+=f"    create_double_matrix(pairint {{BL, BL}}, &bmats.{i});\n"
    for i,j in B_replacements:
        content+=f"    create_double_matrix(pairint {{BL, BL}}, &bmats.{i});\n"

    # generate func calls to fAxi, fBxi
    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in A_replacements+B_replacements:
        idf = str(i)
        content += f"    f{idf}(bmats);\n"

    # generate func calls to fm_i
    for i in range(1, 15137):
        content += f"    fm_{i}(m, bmats);\n"

    for i in range(1,33):
        for j in range(1,33):
            content += (f"    free_double_matrix(bmats.A_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.B_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.C_{i}_{j});\n")
    for i,j in A_replacements:
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

def generate_fAx_source_files(base_dir):
    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    for i,j in A_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        sum_expr = sp.ccode(j)
        sum_expr = re.sub(r'([A-Zx]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', sum_expr)
        sum_expr = re.sub(r'(Ax\d+)', r'bmats.\1.data[i][j]', sum_expr)
        content = f"""\
#include "f{idf}.h"

inline int f{idf}(pack_mats_32x32 bmats) {{
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {{
        for (int j=0; j<BL; j++) {{
            bmats.{idf}.data[i][j] = {sum_expr};
        }}
    }}
    return 0;
}}
"""
        with open(f"{base_dir}/f{idf}.c", "w") as f:
            f.write(content)
    return

def generate_fAx_header_files(base_dir):
    with open("A_replacements.pickle", "rb") as f:
        A_replacements = pickle.load(f)
    for i,j in A_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        content = f"""\
#ifndef F{idf_upper}_H
#define F{idf_upper}_H

#include "stdafx.h"

int f{idf}(pack_mats_32x32 bmats);
#endif
"""
        with open(f"{base_dir}/f{idf}.h", "w") as f:
            f.write(content)
    return

def generate_fBx_source_files(base_dir):
    with open("B_replacements.pickle", "rb") as f:
        B_replacements = pickle.load(f)
    for i,j in B_replacements:
        idf = str(i)
        idf_upper = idf.upper()
        sum_expr = sp.ccode(j)
        sum_expr = re.sub(r'([A-Zx]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', sum_expr)
        sum_expr = re.sub(r'(Bx\d+)', r'bmats.\1.data[i][j]', sum_expr)
        content = f"""\
#include "f{idf}.h"

inline int f{idf}(pack_mats_32x32 bmats) {{
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {{
        for (int j=0; j<BL; j++) {{
            bmats.{idf}.data[i][j] = {sum_expr};
        }}
    }}
    return 0;
}}
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

#include "stdafx.h"

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
generate_fAx_source_files(base_dir)
generate_fAx_header_files(base_dir)
generate_fBx_source_files(base_dir)
generate_fBx_header_files(base_dir)
