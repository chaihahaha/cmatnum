import re
import sympy as sp

with open('m.txt','r') as f:
    s = f.read()
A_expr_str_list = []
B_expr_str_list = []
for line in s.split("\n"):
    if line:
        m, expre = line.split("=")
        fmidx = m.split("_")[1]
        terms = re.findall(r'\((.*?)\)', expre)
        A_pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"
        B_pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(B_\d+_\d+)"
        A_expre = re.match(A_pattern, terms[0])
        B_expre = re.match(B_pattern, terms[1])
        A_expr_str_list.append(A_expre.string)
        B_expr_str_list.append(B_expre.string)
A_expr_list = [sp.parsing.sympy_parser.parse_expr(s) for s in A_expr_str_list]
B_expr_list = [sp.parsing.sympy_parser.parse_expr(s) for s in B_expr_str_list]
A_replacements, A_reduced_exprs = sp.cse(A_expr_list)
B_replacements, B_reduced_exprs = sp.cse(B_expr_list)

print('A replacement', A_replacements)
print('A reduced_exprs', A_reduced_exprs)
print('B replacement', B_replacements)
print('B reduced_exprs', B_reduced_exprs)
