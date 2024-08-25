import os
import re
import sympy as sp


def generate_big_fmmdec(fm_index):
    code = []
    code.append(f"double_cmat tmp_{fm_index}_0, tmp_{fm_index}_1;")
    code.append(f"create_double_matrix(pairint {{BL, BL}}, &tmp_{fm_index}_0);")
    code.append(f"create_double_matrix(pairint {{BL, BL}}, &tmp_{fm_index}_1);")
    return code

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

def generate_big_fmm(expr, fm_index):
    # Extract the two parenthesized terms
    terms = re.findall(r'\((.*?)\)', expr)


    # Function to parse and generate the element-wise computation code
    def parse_and_generate_A_code(terms, tmp):
        sum_expr = terms
        pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"
        sum_expr = re.sub(pattern, symmul12, sum_expr)
        sum_expr = re.sub(r'([A-Z]+\_\d+\_\d+)', r'ABs.\1.data[i][j]', sum_expr)
        return sum_expr


    def parse_and_generate_B_code(terms, tmp):
        sum_expr = terms
        pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"
        sum_expr = re.sub(r'([A-Z]+\_\d+\_\d+)', r'ABs.\1.data[i][j]', sum_expr)
        sum_expr = re.sub(r'/(\d+)', r'/(double)\1', sum_expr)
        return sum_expr

    # Generate code for the first term (tmp0)
    sum_expr_A = parse_and_generate_A_code(terms[0], f"tmp_{fm_index}_0")

    # Generate code for the second term (tmp1)
    sum_expr_B = parse_and_generate_B_code(terms[1], f"tmp_{fm_index}_1")
    return sum_expr_A, sum_expr_B


def get_bigfmm():
    code = []
    with open('m.txt','r') as f:
        s = f.read()
    for line in s.split("\n"):
        if line:
            m, expre = line.split("=")
            fm_index = m.split("_")[1]
            code += generate_big_fmmdec(fm_index)
    code.append(f"for (int i=0; i<BL; i++) {{")
    code.append(f"    for (int j=0; j<BL; j++) {{")
    for line in s.split("\n"):
        if line:
            m, expre = line.split("=")
            fm_index = m.split("_")[1]
            sum_expr_A, sum_expr_B = generate_big_fmm(expre, fm_index)
            code.append(f"        tmp_{fm_index}_0.data[i][j] = {sum_expr_A};")
            code.append(f"        tmp_{fm_index}_0.data[i][j] /= 12.0;")
            code.append(f"        tmp_{fm_index}_1.data[i][j] = {sum_expr_B};")
    code.append(f"    }}")
    code.append(f"}}")

    for line in s.split("\n"):
        if line:
            m, expre = line.split("=")
            fm_index = m.split("_")[1]
            code.append(f"fmm_22x22(m_{fm_index}, tmp_{fm_index}_0, tmp_{fm_index}_1);")
            code.append(f"free_double_matrix(tmp_{fm_index}_0);")
            code.append(f"free_double_matrix(tmp_{fm_index}_1);")

    return "\n".join(code) + "\n"

if __name__ == "__main__":
    with open("bigfmm.txt","w") as f:
        f.write(get_bigfmm())
