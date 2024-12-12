import re
import sympy as sp
import pickle
from collections import defaultdict, deque
from itertools import count
import networkx as nx
import os

def print_edges_with_node_info(G, infos=['name','expr']):
    def get_fs(u, infos):
        fs = f"{u}"
        for i in infos:
            if G.nodes[u][i]:
                fs += f" # ({G.nodes[u][i]})"
        return fs

    for u, v in G.edges():
        fs_u = get_fs(u, infos)
        fs_v = get_fs(v, infos)
        print(f'{fs_u} >>> {fs_v}', end='; ')
    print()


def compute_optimized_order(dep_graph, inputs, outputs):
    # compute optimized order of evaluation of a dependency graph
    # which minimizes the intermediate/tmp variables used

    eval_order = []
    ready_nodes = [node for node in dep_graph.nodes if dep_graph.in_degree(node) == 0]
    used_temps = set()
    max_n_temps = 0
    # Topologically sort the graph
    topo_sorted = list(nx.topological_sort(dep_graph))
    # Determine the last use of each symbol
    last_use = {}
    indexof_lastuse = {}

    for i in range(len(topo_sorted)):
        node = topo_sorted[i]
        for dep in dep_graph.predecessors(node):
            last_use[dep] = node  # update last use for each dependency
            indexof_lastuse[dep] = i
    for n in dep_graph.nodes:
        if n not in indexof_lastuse:
            indexof_lastuse[n] = 0

    is_output = {n:str(n) in outputs for n in dep_graph.nodes}
    
    while ready_nodes:
        #print('#ready_nodes', len(ready_nodes))
        # Sort ready nodes by a priority metric:
        # - prioritize by 'last use' closeness (nodes that can free resources sooner)
        # - prioritize outputs directly if possible
        ready_nodes.sort(
            key=lambda n: (
                is_output[n],                            # outputs have higher priority
                indexof_lastuse[n],   # nodes closer to last use
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
        current_symbol_name = str(current)
        if current_symbol_name not in inputs and current_symbol_name not in outputs:
            used_temps.add(current)
            if last_use[current] == current:  # last time this temp is used
                used_temps.remove(current)
        if len(used_temps)>max_n_temps:
            max_n_temps = len(used_temps)
    print('max opt temp', max_n_temps)
    #print('eval order', eval_order)
    
    return eval_order

def compute_min_intermediates_eval_order(dep_graph, inputs, outputs, tmp_prefix='tmp'):
    # return the evaluation scheme that has least tmp variables used
    opt_sorted = compute_optimized_order(dep_graph.copy(), inputs, outputs)
    
    # Determine the last use of each symbol
    last_use = {}
    for node in opt_sorted:
        for dep in dep_graph.predecessors(node):
            last_use[dep] = node  # update last use for each dependency
    
    # Pool of available temporary symbols
    temp_pool = set()
    active_temps = {}
    max_temps_in_use = 0
    #print('opt sort', opt_sorted)

    tmp_replaced_graph = dep_graph.copy()
    
    for node in opt_sorted:
        # If an expression's dependencies are no longer needed, release temps
        for dep in dep_graph.predecessors(node):
            if dep in last_use and last_use[dep] == node and str(dep) not in inputs:
                temp_pool.add(active_temps[dep])
                del active_temps[dep]
        
        # Assign a temporary symbol for this node's result
        node_symbol_name = str(node)
        if node_symbol_name not in inputs and node_symbol_name not in outputs:
            if temp_pool:
                temp = temp_pool.pop() 
            else:
                temp = f'{tmp_prefix}{len(active_temps) + 1}'
            active_temps[node] = temp
            tmp_replaced_graph.nodes[node]['name'] = temp
            for showing_exprs in dep_graph.successors(node): # successors are not enough should be succ in eval order
                original_expr = tmp_replaced_graph.nodes[showing_exprs]['expr']
                tmp_replaced_graph.nodes[showing_exprs]['expr'] = original_expr.subs(node, temp)
        #print('tmpg:')
        #print_edges_with_node_info(tmp_replaced_graph)
        
        # Update max temps in use
        max_temps_in_use = max(max_temps_in_use, len(active_temps))

    tmp_name_eval_order = [(tmp_replaced_graph.nodes[i]['name'], tmp_replaced_graph.nodes[i]['expr']) for i in opt_sorted if str(i) not in inputs]
    print('max temp variables used:', max_temps_in_use)
    reduced_exprs = [tmp_replaced_graph.nodes[sp.Symbol(i)]['expr'] for i in outputs]
    return tmp_name_eval_order, reduced_exprs

def parse_cse_gen_assignments(expr_list, rep_filename, global_tmp_prefix='Ax', tmp_replace_prefix='Axx', fm_tmp_prefix='mA', inputs_prefix='A_'):
    n_exprs = len(expr_list)
    inputs = [f'{inputs_prefix}{i+1}_{j+1}' for i in range(32) for j in range(32)]
    outputs = [f'{fm_tmp_prefix}{i+1}' for i in range(n_exprs)]
    if os.path.isfile(rep_filename):
        with open(rep_filename, 'rb') as f:
            replacements = pickle.load(f)
    else:
        symbol_generator = (sp.Symbol(f'{global_tmp_prefix}{i}') for i in count())
        replacements, reduced_exprs = sp.cse(expr_list, symbols=symbol_generator, optimizations='basic')
        output_symbols = [sp.Symbol(i) for i in outputs]
        replacements = replacements + list(zip(output_symbols,reduced_exprs))
        #print('cse', replacements)
        with open(rep_filename, 'wb') as f:
            pickle.dump(replacements, f)

    dep_graph = nx.DiGraph()
    for i,j in replacements:
        if isinstance(i,str):
            i = sp.Symbol(i)
        if i not in dep_graph.nodes:
            dep_graph.add_node(i, expr=j, name=str(i))
        else:
            dep_graph.nodes[i]['expr'] = j
        for nj in j.free_symbols:
            nj_name = str(nj)
            if nj not in dep_graph.nodes:
                dep_graph.add_node(nj, expr=None, name=nj_name)
            dep_graph.add_edge(nj, i)
    #print('dep g', end=' ')
    #print_edges_with_node_info(dep_graph)
    eval_order, reduced_exprs = compute_min_intermediates_eval_order(dep_graph, inputs, outputs, tmp_prefix=tmp_replace_prefix)
    return eval_order, reduced_exprs

#a, b, c, d, e, f, g, h, x, y, z = sp.symbols('a b c d e f g h x y z')
#expressions = [(f, a+17*c+e), (g, f+2*b), (h, g+d), (x, g+f+a), (y, f+h+e), (z, h+c+d)]
#inputs = [a, b, c, d, e]
#outputs = [x, y, z]
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

A_eval_order, A_reduced_exprs = parse_cse_gen_assignments(A_expr_list, 'A_replacements.pickle', global_tmp_prefix='Ax', tmp_replace_prefix='Axx', fm_tmp_prefix='mA', inputs_prefix='A_')

with open("A_eval_order.pickle", "wb") as f:
    pickle.dump(A_eval_order,f)
with open("A_reduced_exprs.pickle", "wb") as f:
    pickle.dump(A_reduced_exprs,f)


if not (os.path.isfile('B_replacements.pickle') and os.path.isfile('B_reduced_exprs.pickle')):
    B_expr_list = [sp.parsing.sympy_parser.parse_expr(s) for s in B_expr_str_list]

    symbol_generator = (sp.Symbol(f'Bx{i}') for i in count())
    replacements, reduced_exprs = sp.cse(B_expr_list, symbols=symbol_generator, optimizations='basic')
    with open('B_replacements.pickle', 'wb') as f:
        pickle.dump(replacements, f)
    with open('B_reduced_exprs.pickle', 'wb') as f:
        pickle.dump(reduced_exprs, f)
