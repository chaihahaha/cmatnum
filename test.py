import re
import sympy as sp
import pickle
from collections import defaultdict, deque
from itertools import count

def limited_cse(expressions, min_terms, symbol_generator):
    replacements, reduced_exprs = sp.cse(expressions, symbols=symbol_generator)
    to_be_eliminated_idx = []
    to_be_eliminated = []
    rep_expanded_idx = []
    rep_expanded = []
    
    for i in range(len(replacements)):
        ri = replacements[i]
        if len(ri[1].free_symbols) < min_terms:
            to_be_eliminated_idx.append(i)
            to_be_eliminated.append(ri)
        else:
            rep_expanded_idx.append(i)
    for ei in to_be_eliminated_idx:
        old, new = replacements[ei]
        for i in range(len(replacements)):
            sb, expr = replacements[i]
            if old in expr.free_symbols:
                replacements[i] = (sb, expr.subs(old, new))
        for i in range(len(reduced_exprs)):
            if old in reduced_exprs[i].free_symbols:
                reduced_exprs[i] = reduced_exprs[i].subs(old, new)
    for i in rep_expanded_idx:
        rep_expanded.append(replacements[i])
    
    return rep_expanded, reduced_exprs

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
A_expr_list = [sp.parsing.sympy_parser.parse_expr(s)*12 for s in A_expr_str_list]
B_expr_list = [sp.parsing.sympy_parser.parse_expr(s) for s in B_expr_str_list]
symbol_generator_A = (sp.Symbol(f'Ax{i}') for i in count())
symbol_generator_B = (sp.Symbol(f'Bx{i}') for i in count())
A_replacements, A_reduced_exprs = limited_cse(A_expr_list, 9, symbol_generator_A)
B_replacements, B_reduced_exprs = limited_cse(B_expr_list, 9, symbol_generator_B)

#print('A_replacements:', A_replacements)
#print('A_reduced_exprs:', A_reduced_exprs)
#print('B_replacements:', B_replacements)
#print('B_reduced_exprs:', B_reduced_exprs)

with open("A_replacements.pickle", "wb") as f:
    pickle.dump(A_replacements,f)
with open("A_reduced_exprs.pickle", "wb") as f:
    pickle.dump(A_reduced_exprs,f)
with open("B_replacements.pickle", "wb") as f:
    pickle.dump(B_replacements,f)
with open("B_reduced_exprs.pickle", "wb") as f:
    pickle.dump(B_reduced_exprs,f)

lefts = {str(i) for i,j in A_replacements}
rights = {str(k) for i,j in A_replacements for k in j.free_symbols}
for i in rights:
    if 'x' in i:
        if i not in lefts:
            print(i, lefts)
        assert i in lefts

lefts = {str(i) for i,j in B_replacements}
rights = {str(k) for i,j in B_replacements for k in j.free_symbols}
for i in rights:
    if 'x' in i:
        if i not in lefts:
            print(i, lefts)
        assert i in lefts

