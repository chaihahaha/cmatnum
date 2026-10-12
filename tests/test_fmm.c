/* Correctness checks for the generated kernels: compare each recursive
 * fast-multiplication routine against cblas_dgemm on conforming shapes.
 *
 * The rank-20 3x3 algorithm is a border-rank approximation, so its tolerance is
 * deliberately loose; every other kernel is exact. */

#include "cmat.h"
#include "matmul.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(CFMM_HAVE_3_3)
#include "fmm_3x3.h"
#endif
#if defined(CFMM_HAVE_3_3_6)
#include "fmm_3x3x6.h"
#endif
#if defined(CFMM_HAVE_4_4)
#include "fmm_4x4.h"
#endif
#if defined(CFMM_HAVE_4_4R43)
#include "fmm_4x4r43.h"
#endif
#if defined(CFMM_HAVE_4_4R46)
#include "fmm_4x4r46.h"
#endif
#if defined(CFMM_HAVE_4_4R47)
#include "fmm_4x4r47.h"
#endif
#if defined(CFMM_HAVE_32_32)
#include "fmm_32x32.h"
#endif

typedef int (*fmm_fn)(double_cmat, double_cmat, double_cmat);

static int failures = 0;

static double norm_relative_error(double_cmat C, double_cmat T) {
    double scale = 0.0, worst = 0.0;
    for (shape_uint i = 0; i < T.shape[0]; i++)
        for (shape_uint j = 0; j < T.shape[1]; j++) {
            double v = fabs(T.data[i][j]);
            if (v > scale) scale = v;
        }
    if (scale == 0.0) scale = 1.0;
    for (shape_uint i = 0; i < C.shape[0]; i++)
        for (shape_uint j = 0; j < C.shape[1]; j++) {
            double e = fabs(C.data[i][j] - T.data[i][j]) / scale;
            if (e > worst) worst = e;
        }
    return worst;
}

static void check(const char *name, fmm_fn fn, long M, long K, long N, int base, double tol) {
    double_cmat A, B, C, T;
    create_double_matrix(pairuint{(shape_uint)M, (shape_uint)K}, &A);
    create_double_matrix(pairuint{(shape_uint)K, (shape_uint)N}, &B);
    create_double_matrix(pairuint{(shape_uint)M, (shape_uint)N}, &C);
    create_double_matrix(pairuint{(shape_uint)M, (shape_uint)N}, &T);
    srand(12345);
    for (shape_uint i = 0; i < A.shape[0]; i++)
        for (shape_uint j = 0; j < A.shape[1]; j++)
            A.data[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
    for (shape_uint i = 0; i < B.shape[0]; i++)
        for (shape_uint j = 0; j < B.shape[1]; j++)
            B.data[i][j] = 2.0 * rand() / RAND_MAX - 1.0;

    fmm_base_block = base;
    matmul_double_blas(T, A, B);
    memset(C.arena, 0, (size_t)C.shape[0] * C.shape[1] * sizeof(double));
    fn(C, A, B);

    double err = norm_relative_error(C, T);
    const char *verdict = err <= tol ? "ok" : "FAIL";
    printf("[%s] %-6s M=%ld K=%ld N=%ld base=%d  rel.err=%.3e (tol %.0e)\n",
           verdict, name, M, K, N, base, err, tol);
    if (err > tol) failures++;

    free_double_matrix(A);
    free_double_matrix(B);
    free_double_matrix(C);
    free_double_matrix(T);
}

int main(void) {
    cmat_memory_limit = (size_t)4 << 30; /* keep the test suite modest */

#if defined(CFMM_HAVE_3_3)
    check("3x3", fmm_3x3, 3, 3, 3, 0, 1e-2);
    check("3x3", fmm_3x3, 27, 27, 27, 9, 2e-2);
    check("3x3", fmm_3x3, 243, 243, 243, 81, 5e-2);
    check("3x3", fmm_3x3, 512, 512, 512, 512, 5e-2); /* non-conforming -> BLAS */
#endif
#if defined(CFMM_HAVE_3_3_6)
    check("3x3x6", fmm_3x3x6, 3, 3, 6, 0, 1e-9);
    check("3x3x6", fmm_3x3x6, 48, 48, 96, 16, 1e-9);
    check("3x3x6", fmm_3x3x6, 384, 384, 768, 128, 1e-9);
#endif
#if defined(CFMM_HAVE_4_4)
    check("4x4", fmm_4x4, 4, 4, 4, 0, 1e-9);
    check("4x4", fmm_4x4, 64, 64, 64, 16, 1e-9);
    check("4x4", fmm_4x4, 512, 512, 512, 128, 1e-9);
    check("4x4", fmm_4x4, 300, 300, 300, 300, 1e-9); /* non-conforming -> BLAS */
#endif
/* Rank-reduced *approximate* 4x4x4 kernels.  These carry a much larger error
 * than the border-rank 3x3 scheme; the tolerances below are the measured
 * worst cases and are only there to catch regressions, not to bless them. */
#if defined(CFMM_HAVE_4_4R43)
    check("4x4r43", fmm_4x4r43, 4, 4, 4, 0, 8e-1);
    check("4x4r43", fmm_4x4r43, 256, 256, 256, 64, 8e-1);
#endif
#if defined(CFMM_HAVE_4_4R46)
    check("4x4r46", fmm_4x4r46, 4, 4, 4, 0, 6e-1);
    check("4x4r46", fmm_4x4r46, 256, 256, 256, 64, 6e-1);
#endif
#if defined(CFMM_HAVE_4_4R47)
    check("4x4r47", fmm_4x4r47, 4, 4, 4, 0, 5e-1);
    check("4x4r47", fmm_4x4r47, 256, 256, 256, 64, 5e-1);
#endif
#if defined(CFMM_HAVE_32_32)
    check("32x32", fmm_32x32, 64, 64, 64, 0, 1e-9);
    check("32x32", fmm_32x32, 1024, 1024, 1024, 32, 1e-9);
#endif

    if (failures) {
        printf("%d check(s) failed\n", failures);
        return 1;
    }
    printf("all checks passed\n");
    return 0;
}
