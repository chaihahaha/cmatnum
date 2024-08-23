import os
import re

# Define the base directory for the generated files
base_dir = "generated_files"
os.makedirs(base_dir, exist_ok=True)

# Function to generate the header file content
def generate_packmats_file():
    content = """\
#ifndef PACK_MATS_H
#define PACK_MATS_H
#include<Eigen/Dense>
using Eigen::MatrixXd;
struct pack_mats_22x22 {
"""
    for i in range(1,23):
        for j in range(1,23):
            content+=f"    MatrixXd A_{i}_{j};\n"
            content+=f"    MatrixXd B_{i}_{j};\n"

    content +="""
};
#endif
"""
    return content

def generate_header_file(fm_index):
    content = f"""\
#ifndef FM_{fm_index}_H
#define FM_{fm_index}_H

#include <Eigen/Dense>
#include "pack_mats.h"
#include "fmm_22x22.h"

Eigen::MatrixXd fm_{fm_index}(
"""
    # Add the function parameters (A_1_1 to A_22_22 and B_1_1 to B_22_22)
    params = []
    #for i in range(1, 23):
    #    for j in range(1, 23):
    #        params.append(f"    const Eigen::MatrixXd& A_{i}_{j}")
    #for i in range(1, 23):
    #    for j in range(1, 23):
    #        params.append(f"    const Eigen::MatrixXd& B_{i}_{j}")

    params.append(f"    pack_mats_22x22& ABs")
    content += ",\n".join(params) + ");\n\n"

    content += f"#endif // FM_{fm_index}_H\n"
    return content

# Function to separate the A and B parts using regex
def separate_ab_parts(expression):
    # Find all terms inside the parentheses
    terms = re.findall(r'\((.*?)\)', expression)

    if len(terms) != 2:
        raise ValueError("Expression does not contain two parts inside parentheses.")

    # First part for A matrices, second part for B matrices
    a_expression = terms[0].strip()
    b_expression = terms[1].strip()

    return a_expression, b_expression


# Function to generate the source file content
def generate_source_file(fm_index, expression):
    content = f"""\
#include "fm_{fm_index}.h"
#include "fmm_22x22.h"

Eigen::MatrixXd fm_{fm_index}(
"""
    # Add the function parameters (A_1_1 to A_22_22 and B_1_1 to B_22_22)
    params = []
    #for i in range(1, 23):
    #    for j in range(1, 23):
    #        params.append(f"    const Eigen::MatrixXd& A_{i}_{j}")
    #for i in range(1, 23):
    #    for j in range(1, 23):
    #        params.append(f"    const Eigen::MatrixXd& B_{i}_{j}")
    params.append(f"    pack_mats_22x22& ABs")

    content += ",\n".join(params) + ")\n{\n"
    content += "double num12 = 12.0;\n"

    # Replace matrix multiplication with the custom function call
    
    expression=re.sub(r"([A,B]_\d*_\d*)",r"ABs.\1",expression)
    expression=re.sub(r"/12",r"/num12",expression)
    exp_a, exp_b = separate_ab_parts(expression)
    content += f"    return fmm_22x22({exp_a}, {exp_b});\n"
    content += "}\n"
    return content

def generate_fm_funccall(fm_index):
    return f"MatrixXd m_{fm_index} = fm_{fm_index}(ABs);\n"

def generate_packmats_definitions():
    pack_mats = []
    pack_mats.append("pack_mats_22x22 ABs;\n")
    for i in range(1,23):
        for j in range(1,23):
            pack_mats.append(f"ABs.A_{i}_{j} = A(seq({(i-1)}*BL+1, {i}*BL), seq({(j-1)}*BL+1, {j}*BL));\n")
            pack_mats.append(f"ABs.B_{i}_{j} = B(seq({(i-1)}*BL+1, {i}*BL), seq({(j-1)}*BL+1, {j}*BL));\n")
            #pack_mats.append(f"ABs.C_{i}_{j} = C(seq({(i-1)}*BL+1, {i}*BL), seq({(j-1)}*BL+1, {j}*BL));\n")
    content = "".join(pack_mats)
    return content

def generate_fmm_22x22_header(fm_index):
    return f"#include \"fm_{fm_index}.h\"\n"

# List of matrix expressions
with open('m.txt','r') as f:
    s = f.read()
cab = []
cab.append(generate_packmats_definitions())
cheader = []
for line in s.split("\n"):
    if line:
        m, expre = line.split("=")
        fmidx = m.split("_")[1]
        with open(f"{base_dir}/fm_{fmidx}.h", "w") as f:
            f.write(generate_header_file(fmidx))
        with open(f"{base_dir}/fm_{fmidx}.cpp", "w") as f:
            f.write(generate_source_file(fmidx, expre))
        cab.append(generate_fm_funccall(fmidx))
        cheader.append(generate_fmm_22x22_header(fmidx))
with open(f"AB.txt", "w") as fab:
    fab.write("".join(cab))
with open(f"header.txt", "w") as fheader:
    fheader.write("".join(cheader))
with open(f"{base_dir}/pack_mats.h", "w") as f:
    f.write(generate_packmats_file())
