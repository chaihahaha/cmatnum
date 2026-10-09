/* Minimal standalone check of one 4x4 block: C = A*B for tiny N. */
#include "cmat.h"
#include "matmul.h"
#include "../src/fmm_4x4.h"

#include <stdio.h>

int main(void) {
    fmm_base_block = 0;
    shape_uint N = 4;
    double_cmat A, B, C, T;
    create_double_matrix(pairuint{N, N}, &A);
    create_double_matrix(pairuint{N, N}, &B);
    create_double_matrix(pairuint{N, N}, &C);
    create_double_matrix(pairuint{N, N}, &T);
    for (shape_uint i = 0; i < N; i++)
        for (shape_uint j = 0; j < N; j++) {
            A.data[i][j] = (double)(i * 4 + j + 1);
            B.data[i][j] = (double)(i * 4 + j) * 0.5 - 3.0;
        }
    printf("A:\n"); print_double_matrix(A);
    printf("B:\n"); print_double_matrix(B);
    matmul_double_blas(T, A, B);
    fmm_4x4(C, A, B);
    printf("fmm:\n"); print_double_matrix(C);
    printf("blas:\n"); print_double_matrix(T);
    double worst = 0;
    for (shape_uint i = 0; i < N; i++)
        for (shape_uint j = 0; j < N; j++) {
            double d = fabs(C.data[i][j] - T.data[i][j]);
            if (d > worst) worst = d;
        }
    printf("max abs err = %g\n", worst);
    printf("fast=%lu blas=%lu\n", fmm_4x4_fast_calls, fmm_4x4_blas_calls);
    return worst > 1e-9;
}
