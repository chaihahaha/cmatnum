#include "fmm_32x32.h"
#include <time.h>
#include <stdio.h>

int main() {
    double_cmat A, B, C, TC;
    double_cmat Ac, Bc;
    int N = 32*32*8;
    int M = N;
    create_double_matrix(pairint {N, N}, &A);
    create_double_matrix(pairint {N, N}, &B);
    create_double_matrix(pairint {N, N}, &C);
    create_double_matrix(pairint {N, N}, &TC);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX;
            B.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    //printf("A:\n");
    //print_double_matrix(A);
    //printf("B:\n");
    //print_double_matrix(B);

    clock_t start, end;
    double endtime;

    start = clock();
    fmm_32x32(C, A, B);
    end = clock();
    endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("fmm 32x32 time: %f(s)\n", endtime);

    start = clock();
    matmul_double_blas(TC, A, B);
    end = clock();
    endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("blas time: %f(s)\n", endtime);

    //start = clock();
    //matmul_double_sse2(C, A, B);
    //end = clock();
    //endtime = (double) (end - start)/CLOCKS_PER_SEC;
    //printf("sse2 time: %f(s)\n", endtime);

    //printf("C:\n");
    //print_double_matrix(C);

    //start = clock();
    //matmul_double(TC, A, B);
    //end = clock();
    //endtime = (double) (end - start)/CLOCKS_PER_SEC;
    //printf("naive time: %f(s)\n", endtime);

    ////printf("TC:\n");
    ////print_double_matrix(TC);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fabs(C.data[i][j] - TC.data[i][j]) > 1) {
                printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
            }
        }
    }
    printf("finished\n");
    return 0;
}
