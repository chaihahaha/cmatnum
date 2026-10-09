/* Regression check that the unified generator reproduces the pre-refactor
 * output: run the legacy generated fmm_3x3 (tests/legacy_fmm_3x3.c) and the
 * regenerated one on identical input and compare both with BLAS.
 *
 *   clang -O2 -DUSE_ACCELERATE -DACCELERATE_NEW_LAPACK -D_GNU_SOURCE -Isrc \
 *       tests/compare_legacy_3x3.c tests/legacy_fmm_3x3.c \
 *       src/cmat.c src/matmul.c src/fmm_3x3.c -framework Accelerate -o cmp3
 *   ./cmp3 2187 729
 */
#include "cmat.h"
#include "matmul.h"
#include "fmm_3x3.h"

#include <stdio.h>

int fmm_3x3_orig(double_cmat C, double_cmat A, double_cmat B);

static double norm_err(double_cmat C, double_cmat T) {
    double scale = 0.0, worst = 0.0;
    for (shape_uint i = 0; i < T.shape[0]; i++)
        for (shape_uint j = 0; j < T.shape[1]; j++) {
            double v = fabs(T.data[i][j]);
            if (v > scale) scale = v;
        }
    if (scale == 0) scale = 1;
    for (shape_uint i = 0; i < C.shape[0]; i++)
        for (shape_uint j = 0; j < C.shape[1]; j++) {
            double e = fabs(C.data[i][j] - T.data[i][j]) / scale;
            if (e > worst) worst = e;
        }
    return worst;
}

int main(int argc, char **argv) {
    shape_uint N = argc > 1 ? (shape_uint)atoi(argv[1]) : 243;
    shape_uint base = argc > 2 ? (shape_uint)atoi(argv[2]) : N / 3;
    double_cmat A, B, Cnew, Cold, T;
    create_double_matrix(pairuint{N, N}, &A);
    create_double_matrix(pairuint{N, N}, &B);
    create_double_matrix(pairuint{N, N}, &Cnew);
    create_double_matrix(pairuint{N, N}, &Cold);
    create_double_matrix(pairuint{N, N}, &T);
    srand(7);
    for (shape_uint i = 0; i < N; i++)
        for (shape_uint j = 0; j < N; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
            B.data[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    matmul_double_blas(T, A, B);
    fmm_base_block = (int)base;
    fmm_3x3(Cnew, A, B);
    fmm_3x3_orig(Cold, A, B);
    printf("N=%u base=%u\n", N, base);
    printf("  new  vs BLAS : %.4e\n", norm_err(Cnew, T));
    printf("  orig vs BLAS : %.4e\n", norm_err(Cold, T));
    printf("  new  vs orig : %.4e\n", norm_err(Cnew, Cold));
    return 0;
}
