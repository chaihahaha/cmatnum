#include "fmm_32x32.h"
#include <time.h>
#include <stdio.h>

int main() {
    double_cmat A, B, C, TC;
    double_cmat Ac, Bc;
    int N = 32*32*16;
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

    struct timespec start, end;
    double endtime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    fmm_32x32(C, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("fmm 32x32 time: %f(s)\n", endtime);

    clock_gettime(CLOCK_MONOTONIC, &start);
    matmul_double_blas(TC, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
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

//int main() {
//    double_cmat A1, A2, A3;
//    create_double_matrix(pairint {2, 2}, &A1);
//    create_double_matrix(pairint {2, 2}, &A2);
//    create_double_matrix(pairint {2, 2}, &A3);
//    A1.data[0][0] = 1;
//    A1.data[0][1] = 2;
//    A1.data[1][0] = 3;
//    A1.data[1][1] = 4;
//    A2.data[0][0] = 11;
//    A2.data[0][1] = 22;
//    A2.data[1][0] = 33;
//    A2.data[1][1] = 44;
//    A3.data[0][0] = 2;
//    A3.data[0][1] = 3;
//    A3.data[1][0] = 4;
//    A3.data[1][1] = 5;
//    double_cmat As[3] = {A1, A2, A3};
//    double coeffs[3] = {-1, 2, 1};
//    double_cmat R;
//    create_double_matrix(pairint {2, 2}, &R);
//    matlincomb_double_contiguous(R, 3, (double_cmat*)As, (double*)coeffs);
//    for (int i=0; i<4; i++) {
//        printf("%lf, ", R.arena[i]);
//    }
//    return 0;
//}
