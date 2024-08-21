import numpy as np
import sympy as s

def check_delta(UU,VV,WW):
    delta = np.zeros([2,2,2,2,2,2])
    for i1 in range(2):
        for k1 in range(2):
            for k2 in range(2):
                for j1 in range(2):
                    for i2 in range(2):
                        for j2 in range(2):
                            delta[i1,i2,k1,k2,j1,j2] = np.sum(UU[:,i1*2+k1]*VV[:,k2*2+j1]*WW[:,i2*2+j2])
    for i1 in range(2):
        for k1 in range(2):
            for k2 in range(2):
                for j1 in range(2):
                    for i2 in range(2):
                        for j2 in range(2):
                            assert delta[i1,i2,k1,k2,j1,j2] == ((i1==i2)*(k1==k2)*(j1==j2))

# schwartz 2024
U = np.array([[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1],[0,0,1,1],[0,-1,0,1],[-1,0,0,1]])
V = np.array([[1,0,0,0],[0,0,1,0],[-1,0,0,1],[0,0,0,1],[0,0,1,1],[0,-1,0,1],[0,1,0,0]])
W = np.array([[1,0,0,0],[1,0,0,-1],[0,0,1,0],[0,0,0,-1],[0,1,0,1],[0,0,1,1],[0,-1,0,0]])


phi = np.array([[0,0,1,1],[0,0,0,1],[-1,-1,0,0],[1,0,0,1]])
psi = np.array([[1,0,0,0],[1,1,0,0],[-1,0,1,0],[1,0,0,1]])
invnu = np.array([[0,0,1,-1],[0,0,-1,0],[1,0,0,0],[-1,1,0,-1]])

A = [s.Symbol(f'a{i//2+1}{i%2+1}') for i in range(4)]
B = [s.Symbol(f'b{i//2+1}{i%2+1}') for i in range(4)]
C = [s.Symbol(f'c{i//2+1}{i%2+1}') for i in range(4)]
M = [s.Symbol(f'm{i+1}') for i in range(7)]
PA = [s.Symbol(f'pa{i//2+1}{i%2+1}') for i in range(4)]
PB = [s.Symbol(f'pb{i//2+1}{i%2+1}') for i in range(4)]
PC = [s.Symbol(f'pc{i//2+1}{i%2+1}') for i in range(4)]
print('phi')
phi1 = phi@A
for i in range(4):
    phi1[i] = phi1[i].simplify()
print(phi1.tolist())

print('psi')
psi1 = psi@B
for i in range(4):
    psi1[i] = psi1[i].simplify()
print(psi1.tolist())

print('invnu')
invnu1 = invnu@PC
for i in range(4):
    invnu1[i] = invnu1[i].simplify()
print(invnu1.tolist())

print('S')
S1 = U@PA
for i in range(7):
    S1[i] = S1[i].simplify()
print(S1.tolist())

print('T')
T1 = V@PB
for i in range(7):
    T1[i] = T1[i].simplify()
print(T1.tolist())

print('M')
PC1 = W.T@M
for i in range(4):
    PC1[i] = PC1[i].simplify()
print(PC1.tolist())

U2 = U@phi
V2 = V@psi
W2 = W@invnu.T
check_delta(U2,V2,W2)
CC = invnu@(((U@phi@A)*(V@psi@B))@W).T
for i in range(4):
    CC[i] = CC[i].simplify()
print(CC.tolist())
#print(phi.flatten().tolist())
#print(psi.flatten().tolist())
#print(invnu.flatten().tolist())
