#include "fmm_32x32.h"
#include "matmul.h"
#include <time.h>
#include <stdio.h>

int main() {
    double_cmat A, B, C;
    int N = 32*1024;
    printf("performing %d x %d matmul...\n", N, N);
    int M = N;
    create_double_matrix(pairint {N, N}, &A);
    create_double_matrix(pairint {N, N}, &B);
    create_double_matrix(pairint {N, N}, &C);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX;
            B.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    struct timespec start, end;
    double endtime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("fmm<32x32x32:15136>\n");
    fmm_32x32(C, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("fmm 32x32 time: %f(s)\n", endtime);

    double_cmat TC;
    create_double_matrix(pairint {N, N}, &TC);
    clock_gettime(CLOCK_MONOTONIC, &start);
    matmul_double_blas(TC, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("blas time: %f(s)\n", endtime);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fabs(C.data[i][j] - TC.data[i][j]) > 0.1) {
                printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
                return -1;
            }
        }
    }
    printf("finished\n");
    return 0;

    free_double_matrix(A);
    free_double_matrix(B);
    free_double_matrix(C);
    free_double_matrix(TC);
    printf("finished\n");
    return 0;
}
