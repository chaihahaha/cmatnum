#include "fmm_22x22.h"
#include <time.h>
#include <stdio.h>

int main() {
    double_cmat A, B, C, TC;
    double_cmat AA, BB, CC;
    double_cmat Ac, Bc;
    int N = 22*22*22;
    int M = 2048*5;
    create_double_matrix(pairint {N, N}, &A);
    create_double_matrix(pairint {N, N}, &B);
    create_double_matrix(pairint {N, N}, &C);
    //create_double_matrix(pairint {N, N}, &TC);

    create_double_matrix(pairint {M, M}, &AA);
    create_double_matrix(pairint {M, M}, &BB);
    create_double_matrix(pairint {M, M}, &CC);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX;
            B.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            AA.data[i][j] = 2.0 * rand() / RAND_MAX;
            BB.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    //printf("A:\n");
    //print_double_matrix(A);
    //printf("B:\n");
    //print_double_matrix(B);

    clock_t start, end;
    double endtime;

    start = clock();
    matmul_double_schwartz2024(CC, AA, BB);
    end = clock();
    endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("schwartz2024 time: %f(s)\n", endtime);

    start = clock();
    fmm_22x22(C, A, B);
    end = clock();
    endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("fmm 22x22 time: %f(s)\n", endtime);

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

    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        if (fabs(C.data[i][j] - TC.data[i][j]) > 1) {
    //            printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
    //        }
    //    }
    //}
    printf("finished\n");
    return 0;
}
