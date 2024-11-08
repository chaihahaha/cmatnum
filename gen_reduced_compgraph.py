import re
import sympy as sp
import pickle
from collections import defaultdict, deque
from itertools import count
import networkx as nx

def dependency_resolution(assignments):
    # Step 1: Create a directed graph where each symbol points to its dependencies
    G = nx.DiGraph()
    
    # Add nodes and edges based on dependencies in the assignments
    for lhs, rhs in assignments:
        G.add_node(lhs)
        for symbol in rhs.free_symbols:
            # Add an edge if rhs has a dependency on another assignment's lhs
            if symbol != lhs:  # Prevent self-loops
                G.add_edge(lhs, symbol)
    
    # Step 2: Topologically sort the nodes (i.e., order assignments for valid evaluation)
    try:
        sorted_lhs = list(nx.topological_sort(G))
    except nx.NetworkXUnfeasible:
        raise ValueError("The assignments contain circular dependencies and cannot be evaluated in order.")
    
    # Step 3: Sort the original list of assignments based on the topological order
    sorted_assignments = sorted(assignments, key=lambda x: sorted_lhs.index(x[0]), reverse=True)
    return sorted_assignments

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

def compute_optimized_order(dep_graph, inputs, outputs):
    # compute optimized order of evaluation of a dependency graph
    # which minimizes the intermediate/tmp variables used

    eval_order = []
    ready_nodes = [node for node in dep_graph.nodes if dep_graph.in_degree(node) == 0]
    used_temps = set()
    # Topologically sort the graph
    topo_sorted = list(nx.topological_sort(dep_graph))
    # Determine the last use of each symbol
    last_use = {}
    for node in topo_sorted:
        for dep in dep_graph.predecessors(node):
            last_use[dep] = node  # update last use for each dependency
    
    while ready_nodes:
        # Sort ready nodes by a priority metric:
        # - prioritize by 'last use' closeness (nodes that can free resources sooner)
        # - prioritize outputs directly if possible
        ready_nodes.sort(
            key=lambda n: (
                n in outputs,                            # outputs have higher priority
                topo_sorted.index(last_use.get(n, n)),   # nodes closer to last use
                dep_graph.out_degree(n)                  # fewer dependencies get higher priority
            ),
            reverse=True
        )
        
        # Choose the highest priority node to evaluate
        current = ready_nodes.pop(0)
        eval_order.append(current)
        
        # Update dependencies and ready nodes list
        for succ in list(dep_graph.successors(current)):
            dep_graph.remove_edge(current, succ)
            if dep_graph.in_degree(succ) == 0:
                ready_nodes.append(succ)
        
        # Track usage of temporary symbols
        if current not in inputs and current not in outputs:
            used_temps.add(current)
            if last_use[current] == current:  # last time this temp is used
                used_temps.remove(current)
    
    return eval_order

def compute_min_intermediates_evaluation_scheme(dep_graph, inputs, outputs):
    # return the evaluation scheme that has least tmp variables used
    opt_sorted = compute_optimized_order(dep_graph.copy(), inputs, outputs)
    
    # Determine the last use of each symbol
    last_use = {}
    for node in opt_sorted:
        for dep in dep_graph.predecessors(node):
            last_use[dep] = node  # update last use for each dependency
    print(last_use)
    
    # Pool of available temporary symbols
    temp_pool = set()
    active_temps = {}
    max_temps_in_use = 0
    #print('opt sort', opt_sorted)

    tmp_replaced_graph = dep_graph.copy()
    
    for node in opt_sorted:
        # If an expression's dependencies are no longer needed, release temps
        for dep in dep_graph.predecessors(node):
            if dep in last_use and last_use[dep] == node and dep not in inputs:
                temp_pool.add(active_temps[dep])
                del active_temps[dep]
        
        # Assign a temporary symbol for this node's result
        if node not in inputs and node not in outputs:
            if temp_pool:
                temp = temp_pool.pop()
            else:
                temp = f'temp{len(active_temps) + 1}'
            active_temps[node] = temp
            tmp_replaced_graph.nodes[node]['name'] = temp
            for showing_exprs in dep_graph.successors(node):
                original_expr = tmp_replaced_graph.nodes[showing_exprs]['expr']
                tmp_replaced_graph.nodes[showing_exprs]['expr'] = original_expr.subs(node, temp)
        
        # Update max temps in use
        max_temps_in_use = max(max_temps_in_use, len(active_temps))

        #print('node', node)
        #print('succ', list(dep_graph.successors(node)))
    
    evaluation_scheme = [(tmp_replaced_graph.nodes[i]['name'], tmp_replaced_graph.nodes[i]['expr']) for i in opt_sorted if i not in inputs]
    print('max temp variables used:', max_temps_in_use)
    return evaluation_scheme

#a, b, c, d, e, f, g, h, x, y, z = sp.symbols('a b c d e f g h x y z')
#expressions = [(f, a+17*c+e), (g, f+2*b), (h, g+d), (x, g+f+a), (y, f+h+e), (z, h+c+d)]
#inputs = [a, b, c, d, e]
#outputs = [x, y, z]
#dep_graph = nx.DiGraph()
#for i,j in expressions:
#    if i not in dep_graph.nodes:
#        dep_graph.add_node(i, expr=j, name=str(i))
#    for nj in j.free_symbols:
#        if nj not in dep_graph.nodes:
#            dep_graph.add_node(nj, expr=None, name=str(nj))
#        dep_graph.add_edge(nj, i)
#eval_scheme = compute_min_intermediates_evaluation_scheme(dep_graph, inputs, outputs)
#print(eval_scheme)

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
A_expr_list = [sp.parsing.sympy_parser.parse_expr(s)*17 for s in A_expr_str_list]
B_expr_list = [sp.parsing.sympy_parser.parse_expr(s) for s in B_expr_str_list]
symbol_generator_A = (sp.Symbol(f'Ax{i}') for i in count())
symbol_generator_B = (sp.Symbol(f'Bx{i}') for i in count())
A_replacements, A_reduced_exprs = limited_cse(A_expr_list, 10, symbol_generator_A)
A_rep_lhs = [i[0] for i in A_replacements]
A_rep_rhs = [i[1] for i in A_replacements]
A_rhs_replacements, A_rhs_reduced_exprs = limited_cse(A_rep_rhs, 4, symbol_generator_A)
A_replacements = A_rhs_replacements + list(zip(A_rep_lhs, A_rhs_reduced_exprs)) # wrong order, should be topo sorted
A_replacements = dependency_resolution(A_replacements)
print(A_replacements, A_reduced_exprs)

B_replacements, B_reduced_exprs = limited_cse(B_expr_list, 10, symbol_generator_B)
B_rep_lhs = [i[0] for i in B_replacements]
B_rep_rhs = [i[1] for i in B_replacements]
B_rhs_replacements, B_rhs_reduced_exprs = limited_cse(B_rep_rhs, 4, symbol_generator_B)
B_replacements = B_rhs_replacements + list(zip(B_rep_lhs, B_rhs_reduced_exprs))
B_replacements = dependency_resolution(B_replacements)
print(B_replacements, B_reduced_exprs)

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

