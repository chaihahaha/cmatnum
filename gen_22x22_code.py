import os
import re
import sympy as sp
from collections import defaultdict
from sympy.parsing.sympy_parser import parse_expr

# Define the base directory for the generated files
base_dir = "generated_files"
os.makedirs(base_dir, exist_ok=True)

# Function to generate the header file content
def generate_packmats_file(base_dir):
    content = """\
#ifndef PACK_MATS_H
#define PACK_MATS_H
#include "cmat.h"
struct pack_mats_22x22 {
"""
    for i in range(1,23):
        for j in range(1,23):
            content+=f"    double_cmat A_{i}_{j};\n"
            content+=f"    double_cmat B_{i}_{j};\n"
            content+=f"    double_cmat C_{i}_{j};\n"

    for i in range(4093):
        content+=f"    double_cmat Ax{i};\n"
    for i in range(4712):
        content+=f"    double_cmat Bx{i};\n"

    content +="""
};
typedef struct pack_mats_22x22 pack_mats_22x22;
#endif
"""
    filename = f"{base_dir}/pack_mats.h"
    with open(filename, "w") as f:
        f.write(content)
    return 

def generate_fm_header_files(base_dir):
    for fm_index in range(1, 5567):
        content = f"""\
#ifndef FM_{fm_index}_H
#define FM_{fm_index}_H

#include "stdafx.h"
int fmm_22x22(double_cmat C, double_cmat A, double_cmat B);

int fm_{fm_index}(double_cmat m, pack_mats_22x22 bmats);
#endif
"""
        with open(f"{base_dir}/fm_{fm_index}.h", "w") as f:
            f.write(content)
    return content


# Function to generate the source file content
def generate_fm_source_files(base_dir):
    m_terms = [sp.Symbol(f"m_{i}") for i in range(1, 5567)]
    d_mterms = {str(i): i for i in m_terms}
    #A_terms = [[sp.Symbol(f"A_{i}_{j}") for j in range(1, 23)] for i in range(1, 23)]
    #d_Aterms = {str(i): i for i in sum(A_terms,[])}
    #B_terms = [[sp.Symbol(f"B_{i}_{j}") for j in range(1, 23)] for i in range(1, 23)]
    #d_Bterms = {str(i): i for i in sum(B_terms,[])}

    with open("C.txt", "r") as f:
        Cs = f.read()
    m_to_C = get_m_to_C_inc_mapping(Cs, d_mterms)

    with open('m.txt','r') as f:
        s = f.read()
    for line in s.split("\n"):
        if line:
            m, expre = line.split("=")
            fm_index = m.split("_")[1]
            terms = re.findall(r'\((.*?)\)', expre)

            content = f"""\
#include "fm_{fm_index}.h"

inline int fm_{fm_index}(double_cmat m, pack_mats_22x22 bmats) {{
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {{BL, BL}}, &tmp0);
    create_double_matrix(pairint {{BL, BL}}, &tmp1);
"""
        
            sum_expr_A = sp.ccode(parse_expr(terms[0])*12)
            sum_expr_A = re.sub(r'([A-Z]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', sum_expr_A)
            sum_expr_B = re.sub(r'([A-Z]+\_\d+\_\d+)', r'bmats.\1.data[i][j]', terms[1])

            content += f"""\
    for (int i=0; i<BL; i++) {{
        for (int j=0; j<BL; j++) {{
            tmp0.data[i][j] = {sum_expr_A};
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = {sum_expr_B};
        }}
    }}
    fmm_22x22(m, tmp0, tmp1);

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


def generate_fmm_22x22_header():
    content = """\
#ifndef FMM_22X22_H
#define FMM_22X22_H

#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include "matmul.h"
"""
    for fm_index in range(1, 5567):
        content += (f"#include \"fm_{fm_index}.h\"\n")
    content += """\
int fmm_22x22(double_cmat C, double_cmat A, double_cmat B);

#endif
"""
    with open("fmm_22x22_h.txt", "w") as f:
        f.write(content)
    return

def generate_fmm_22x22_source():
    content = """\
#include "fmm_22x22.h"

int fmm_22x22(double_cmat C, double_cmat A, double_cmat B) {
    int height = A.shape[0];
    int width = A.shape[1];
    if (height <= 22 || width <= 22) {
        matmul_double(C, A, B);
        return 0;
    }
    if (!(height % 22 == width % 22 && height % 22 == 0 && height / 22 == width / 22)) {
        //return matmul_double(C, A, B);
        return -1;
    }
    int N = height;
    int BL = N/22;
    int NS = BL*BL;
    double_cmat m;
    create_double_matrix(pairint {BL, BL}, &m);
"""

    content += ("pack_mats_22x22 bmats;\n")
    for i in range(1,23):
        for j in range(1,23):
            content += (f"    bmats.A_{i}_{j} = slice_double_matrix(A, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            content += (f"    bmats.B_{i}_{j} = slice_double_matrix(B, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            content += (f"    bmats.C_{j}_{i} = slice_double_matrix(C, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")


    for i in range(1, 5567):
        content += f"    fm_{i}(m, bmats);\n"

    for i in range(1,23):
        for j in range(1,23):
            content += (f"    free_double_matrix(bmats.A_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.B_{i}_{j});\n")
            content += (f"    free_double_matrix(bmats.C_{i}_{j});\n")
    content += """\
    free_double_matrix(m);
    return 0;
}
"""
    with open("fmm_22x22_c.txt", "w") as f:
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

generate_fmm_22x22_header()
generate_fmm_22x22_source()
generate_fm_source_files(base_dir)
generate_packmats_file(base_dir)
generate_fm_header_files(base_dir)

