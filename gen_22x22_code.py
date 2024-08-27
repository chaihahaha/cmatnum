import os
import re
import sympy as sp
from collections import defaultdict

# Define the base directory for the generated files
base_dir = "generated_files"
os.makedirs(base_dir, exist_ok=True)

# Function to generate the header file content
def generate_packmats_file():
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

    content +="""
};
typedef struct pack_mats_22x22 pack_mats_22x22;
#endif
"""
    return content

def generate_header_file(fm_index):
    content = f"""\
#ifndef FM_{fm_index}_H
#define FM_{fm_index}_H

#include "stdafx.h"
int fmm_22x22(double_cmat C, double_cmat A, double_cmat B);

int fm_{fm_index}(double_cmat m, pack_mats_22x22 ABs);
#endif
"""
    return content

def symmul12(match):
    fraction_str = match.group(1)
    slash = match.group(2)
    term = match.group(3)
    #print('frac term', fraction_str, term, match.group(2))

    if slash is None or fraction_str in ["+", "-", ""]:
        # Default coefficient is +1 or -1
        fraction = sp.Rational(f"{fraction_str}1") if fraction_str else sp.Rational(1)
    else:
        # Use the matched fraction or integer
        fraction = sp.Rational(fraction_str.replace('*', ''))

    # Multiply by 12
    simplified_fraction = fraction * 12

    # Construct the resulting string
    if simplified_fraction == 1:
        return f"+{term}"
    elif simplified_fraction == -1:
        return f"-{term}"
    elif simplified_fraction > 0:
        return f"+{simplified_fraction}*{term}"
    else:
        return f"{simplified_fraction}*{term}"

# Function to generate the source file content
def generate_source_file(fm_index, expression):
    code = []
    code.append(f"""\
#include "fm_{fm_index}.h"

inline int fm_{fm_index}(double_cmat m, pack_mats_22x22 ABs) {{
""")

    # Extract the two parenthesized terms
    terms = re.findall(r'\((.*?)\)', expression)

    # Initialize a list to hold the generated code

    # Create temporary matrices tmp0 and tmp1
    code.append("double dnum12 = 1/12.0;\n")
    code.append("int BL = ABs.A_1_1.shape[0];")
    code.append("double_cmat tmp0, tmp1;")
    code.append("create_double_matrix(pairint {BL, BL}, &tmp0);")
    code.append("create_double_matrix(pairint {BL, BL}, &tmp1);")
    #code.append("print_double_matrix(ABs.A_1_1);")
    #A = [[sp.Symbol(f'A_{i+1}_{j+1}') for j in range(22)] for i in range(22)]
    #A_locals = {f'A_{i+1}_{j+1}': A[i][j] for i in range(22) for j in range(22)}
    
    # Function to parse and generate the element-wise computation code
    def parse_and_generate_A_code(terms):
        sum_expr = terms
        pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"
        sum_expr = re.sub(pattern, symmul12, sum_expr)
        #if sp.simplify(sp.sympify(sum_expr, locals=A_locals) - 12*sp.sympify(terms, locals=A_locals)) != 0:
        #    print(terms)
        #    print(sum_expr)
        #    print('exiting')
        #    exit()
        sum_expr = re.sub(r'([A-Z]+\_\d+\_\d+)', r'ABs.\1.data[i][j]', sum_expr)
        #sum_expr = re.sub(r'/(\d+)', r'/(double)\1', sum_expr)
        return sum_expr


    def parse_and_generate_B_code(terms):
        sum_expr = terms
        pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"
        sum_expr = re.sub(r'([A-Z]+\_\d+\_\d+)', r'ABs.\1.data[i][j]', sum_expr)
        sum_expr = re.sub(r'/(\d+)', r'/(double)\1', sum_expr)
        return sum_expr

    sum_expr_A = parse_and_generate_A_code(terms[0])
    sum_expr_B = parse_and_generate_B_code(terms[1])

    code.append(f"for (int i=0; i<BL; i++) {{")
    code.append(f"    for (int j=0; j<BL; j++) {{")
    code.append(f"        tmp0.data[i][j] = {sum_expr_A};")
    code.append(f"        tmp0.data[i][j] *= dnum12;")
    code.append(f"        tmp1.data[i][j] = {sum_expr_B};")
    code.append(f"    }}")
    code.append(f"}}")

    code.append("fmm_22x22(m, tmp0, tmp1);")
    code.append("free_double_matrix(tmp0);")
    code.append("free_double_matrix(tmp1);")

    code.append(f"    return 0;\n")
    code.append("}\n")
    return "\n".join(code) + "\n"

def generate_fm_funccall(fm_index):
    return f"fm_{fm_index}(m, &ABs);\n"

def generate_packmats_definitions():
    pack_mats = []
    pack_mats.append("pack_mats_22x22 ABs;\n")
    for i in range(1,23):
        for j in range(1,23):
            #pack_mats.append(f"create_double_matrix(pairint {{BL, BL}}, &ABs.A_{i}_{j});\n")
            #pack_mats.append(f"create_double_matrix(pairint {{BL, BL}}, &ABs.B_{i}_{j});\n")
            pack_mats.append(f"ABs.A_{i}_{j} = slice_double_matrix(A, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            pack_mats.append(f"ABs.B_{i}_{j} = slice_double_matrix(B, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
            pack_mats.append(f"double_cmat C_{j}_{i} = slice_double_matrix(C, pairint {{{(i-1)}*BL, {i}*BL}}, pairint {{{(j-1)}*BL, {j}*BL}});\n")
    for i in range(1,23):
        for j in range(1,23):
            pack_mats.append(f"free_double_matrix(ABs.A_{i}_{j});\n")
            pack_mats.append(f"free_double_matrix(ABs.B_{i}_{j});\n")
            pack_mats.append(f"free_double_matrix(C_{i}_{j});\n")
    content = "".join(pack_mats)
    return content

def generate_fmm_22x22_header(fm_index):
    return f"#include \"fm_{fm_index}.h\"\n"

# List of matrix expressions
with open('m.txt','r') as f:
    s = f.read()
with open('C.txt','r') as f:
    Cs = f.read()
m_to_C = defaultdict(list)
pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(m_\d+)"
for line in Cs.split("\n"):
    if line:
        Ci, formula = line.split("=")
        matches = re.findall(pattern, formula)
        for mat in matches:
            if mat[0]:
                if mat[0].endswith("*"):
                    coefficient = mat[0][:-1]
                else:
                    coefficient = mat[0]
                if mat[0] in ["+","-"]:
                    coefficient = mat[0] + "1"
            else:
                coefficient = "1"
            m_term = mat[2]
            m_to_C[m_term].append((Ci, coefficient))
code = []
for m_term in m_to_C.keys():
    code.append(f"f{m_term}(m, ABs);")
    code.append(f"for (int i=0; i<BL; i++) {{")
    code.append(f"    for (int j=0; j<BL; j++) {{")
    for Ci, coefficient in m_to_C[m_term]:
        code.append(f"        {Ci}.data[i][j]+={coefficient} * m.data[i][j];")
    code.append(f"    }}")
    code.append(f"}}")
incremental_m = "\n".join(code)
with open("inc_m.txt","w") as f:
    f.write(incremental_m)
cab = []
cab.append(generate_packmats_definitions())
cheader = []
m_defs = []
m_frees = []
m_defs.append(f"double_cmat m;\ncreate_double_matrix(pairint {{BL,BL}}, &m);\n")
m_frees.append(f"free_double_matrix(m);\n")
for line in s.split("\n"):
    if line:
        m, expre = line.split("=")
        fmidx = m.split("_")[1]
        with open(f"{base_dir}/fm_{fmidx}.h", "w") as f:
            f.write(generate_header_file(fmidx))
        with open(f"{base_dir}/fm_{fmidx}.c", "w") as f:
            f.write(generate_source_file(fmidx, expre))
        #cab.append(generate_fm_funccall(fmidx))
        cheader.append(generate_fmm_22x22_header(fmidx))
with open(f"AB.txt", "w") as fab:
    fab.write("".join(cab))
with open(f"header.txt", "w") as fheader:
    fheader.write("".join(cheader))
with open(f"mdef.txt", "w") as fm:
    fm.write("".join(m_defs+m_frees))
with open(f"{base_dir}/pack_mats.h", "w") as f:
    f.write(generate_packmats_file())
