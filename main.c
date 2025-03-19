//#include "fmm_32x32.h"
//#include "fmm_3x3x6.h"
#include "fmm_3x3.h"
#include "matmul.h"
#include <time.h>
#include <stdio.h>

int main() {
    double_cmat A, B, C;
    int AH = 20100;
    int AW = 20100;
    int BH = AW;
    int BW = 20100;
    //int AH = 32*1024;
    //int AW = 32*1024;
    //int BH = AW;
    //int BW = 32*1024;
    int CH = AH;
    int CW = BW;
    printf("performing %d x %d x %d matmul...\n", AH, AW, BW);
    create_double_matrix(pairuint {AH, AW}, &A);
    create_double_matrix(pairuint {BH, BW}, &B);
    create_double_matrix(pairuint {CH, CW}, &C);

    for (int i = 0; i < AH; i++) {
        for (int j = 0; j < AW; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < BH; i++) {
        for (int j = 0; j < BW; j++) {
            B.data[i][j] = 2.0 * rand() / RAND_MAX;
        }
    }
    struct timespec start, end;
    double endtime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("fmm<3x3x3:20>\n");
    //printf("fmm<3x3x6:40>\n");
    //printf("fmm<32x32x32:15136>\n");
    //fmm_32x32(C, A, B);
    //fmm_3x3x6(C, A, B);
    fmm_3x3(C, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    //printf("fmm 32x32 time: %f(s)\n", endtime);
    //printf("fmm 3x3x6 time: %f(s)\n", endtime);
    printf("fmm 3x3x3 time: %f(s)\n", endtime);

    double_cmat TC;
    create_double_matrix(pairuint {CH, CW}, &TC);
    clock_gettime(CLOCK_MONOTONIC, &start);
    matmul_double_blas(TC, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("blas time: %f(s)\n", endtime);

    for (int i = 0; i < CH; i++) {
        for (int j = 0; j < CW; j++) {
            if (fabs(C.data[i][j] - TC.data[i][j]) > 0.02*TC.data[i][j]) {
                printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
                return -1;
            }
        }
    }

    free_double_matrix(A);
    free_double_matrix(B);
    free_double_matrix(C);
    free_double_matrix(TC);
    printf("finished\n");
    return 0;
}
