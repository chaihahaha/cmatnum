/* Minimal standalone check of one 3x3 block: C = A*B for N=3. */
#include "cmat.h"
#include "matmul.h"
#include "../src/fmm_3x3.h"

#include <stdio.h>

int main(void) {
    fmm_base_block = 0;
    shape_uint N = 3;
    double_cmat A, B, C, T;
    create_double_matrix(pairuint{N, N}, &A);
    create_double_matrix(pairuint{N, N}, &B);
    create_double_matrix(pairuint{N, N}, &C);
    create_double_matrix(pairuint{N, N}, &T);
    for (shape_uint i = 0; i < N; i++)
        for (shape_uint j = 0; j < N; j++) {
            A.data[i][j] = (double)(i * 3 + j + 1);
            B.data[i][j] = (double)(i * 3 + j) * 0.5 - 3.0;
        }
    matmul_double_blas(T, A, B);
    fmm_3x3(C, A, B);
    printf("fmm:\n"); print_double_matrix(C);
    printf("blas:\n"); print_double_matrix(T);
    return 0;
}
