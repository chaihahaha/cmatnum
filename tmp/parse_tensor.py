"""Throwaway: parse assets/4x4x4_tensor.mpl TriadSet and verify the algorithm."""
import re
import sys
import sympy as sp

path = sys.argv[1] if len(sys.argv) > 1 else "assets/4x4x4_tensor.mpl"
s = open(path).read()

# isolate the TriadSet(...) argument
m = re.search(r"TriadSet\(\[(.*)\]\)\s*:", s, re.S)
assert m, "TriadSet not found"
body = m.group(1)

parts = [p for p in re.split(r"Triad\(", body) if p.strip()]
print("n triads:", len(parts))

triads = []
for p in parts:
    mats = re.findall(r"Matrix\(\s*(\d+)\s*,\s*(\d+)\s*,\s*(\[\[.*?\]\])\s*\)", p, re.S)
    assert len(mats) == 3, (len(mats), p[:200])
    ms = []
    for r, c, lit in mats:
        assert r == c and int(r) in (4,)
        ms.append(sp.Matrix(sp.sympify(lit)))
    triads.append(tuple(ms))

A = sp.Matrix(4, 4, lambda i, j: sp.Symbol(f"A_{i+1}_{j+1}"))
B = sp.Matrix(4, 4, lambda i, j: sp.Symbol(f"B_{i+1}_{j+1}"))
target = A * B

def build(ct):
    C = sp.zeros(4, 4)
    for (Ai, Bi, Ci) in triads:
        ca = sum(Ai[p, q] * A[p, q] for p in range(4) for q in range(4))
        cb = sum(Bi[p, q] * B[p, q] for p in range(4) for q in range(4))
        C += ca * cb * ct(Ci)
    return C

for name, ct in [("C_i", lambda M: M), ("C_i^T", lambda M: M.T)]:
    C = build(ct)
    diff = sp.expand(C - target)
    ok = all(v == 0 for v in diff)
    print(f"convention {name}: exact={ok}")
    if not ok:
        nz = [(i, j, diff[i, j]) for i in range(4) for j in range(4) if diff[i, j] != 0]
        print("  nonzero residual:", nz[:4])

# rank / coefficient stats
coeffs = set()
for (Ai, Bi, Ci) in triads:
    for M in (Ai, Bi, Ci):
        coeffs |= {sp.nsimplify(v) for v in M}
print("coefficients:", sorted(coeffs, key=str))
print("n nonzero per triad A/B/C:",
      [tuple(int(sum(1 for v in M if v != 0)) for M in t) for t in triads[:8]], "...")
print("sparsity A,B,C totals:",
      tuple(sum(1 for t in triads for v in t[k] if v != 0) for k in range(3)))
