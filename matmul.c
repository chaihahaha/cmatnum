#include "matmul.h"

int matmul_float(float_cmat matC, float_cmat matA, float_cmat matB){
    if (matA.shape[1] != matB.shape[0]) {
        return -1;
    }
    int M = matA.shape[0];
    int N = matB.shape[1];
    int K = matB.shape[0];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            float sum = 0.0f;
            for(int k = 0; k < K; k++){
                sum += matA.data[i][k] * matB.data[k][j];
            }
            matC.data[i][j] = sum;
        }
    }
    return 0;
}

int matmul_double(double_cmat matC, double_cmat matA, double_cmat matB){
    if (matA.shape[1] != matB.shape[0]) {
        return -1;
    }
    int M = matA.shape[0];
    int N = matB.shape[1];
    int K = matB.shape[0];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            double sum = 0.0f;
            for(int k = 0; k < K; k++){
                sum += matA.data[i][k] * matB.data[k][j];
            }
            matC.data[i][j] = sum;
        }
    }
    return 0;
}

int matmul_double_blas(double_cmat C, double_cmat A_slice, double_cmat B_slice) {
    //printf("start matmul blas %d %d\n", A_slice.shape[0], A_slice.shape[1]);
    // Check dimensions for compatibility
    //if (A_slice.shape[1] != B_slice.shape[0] || A_slice.shape[0] != C.shape[0] || B_slice.shape[1] != C.shape[1]) {
    //    fprintf(stderr, "Matrix dimensions do not match for multiplication.\n");
    //    return -1;
    //}
    //for(int arenai=0; arenai<NS; arenai++) C.arena[arenai] = 0;
        // Call dgemm
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A_slice.shape[1],
                    1.0, A_slice.data[0], A_slice.arena_shape[1],
                    B_slice.data[0], B_slice.arena_shape[1],
                    0.0, C.data[0], C.arena_shape[1]);
    //printf("finish matmul blas\n");
    return 0;
}

int matmul_double_blas_nocontig(double_cmat C, double_cmat A_slice, double_cmat B_slice) {
    // Check dimensions for compatibility
    if (A_slice.shape[1] != B_slice.shape[0] || A_slice.shape[0] != C.shape[0] || B_slice.shape[1] != C.shape[1]) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication.\n");
        return -1;
    }
    double_cmat CC;
    create_double_matrix(pairuint {C.shape[0], C.shape[1]}, &CC);

    if (is_contiguous_double(A_slice) && is_contiguous_double(B_slice)) {
        // Call dgemm
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A_slice.shape[1],
                    1.0, A_slice.data[0], A_slice.arena_shape[1],
                    B_slice.data[0], B_slice.arena_shape[1],
                    0.0, CC.arena, CC.arena_shape[1]);
    }
    else {
        double_cmat A,B;
        create_double_contiguous_from_slice(&A, &A_slice);
        create_double_contiguous_from_slice(&B, &B_slice);

        // Call dgemm
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A.shape[1],
                    1.0, A.arena, A.arena_shape[1],
                    B.arena, B.arena_shape[1],
                    0.0, CC.arena, CC.arena_shape[1]);
        free_double_matrix(A);
        free_double_matrix(B);
    }
    assign_double_clone(C, CC);
    free_double_matrix(CC);
    return 0;
}

int matmul_double_strassen_winograd(double_cmat matC, double_cmat matA, double_cmat matB){
    /*
     * matA M*K
     * matB K*N
     * matC M*N
     * matC = matA * matB
     * S1 = A21 + A22     T1 = B12 - B11
     * S2 = S1 - A11      T2 = B22 - T1
     * S3 = A11 - A21     T3 = B22 - B12
     * S4 = A12 - S2      T4 = T2 - B21
     * M1 = A11 * B11     U1 = M1 + M2
     * M2 = A12 * B21     U2 = M1 + M6
     * M3 = S4 * B22      U3 = U2 + M7
     * M4 = A22 * T4      U4 = U2 + M5
     * M5 = S1 * T1       U5 = U4 + M3
     * M6 = S2 * T2       U6 = U3 - M4
     * M7 = S3 * T3       U7 = U3 + M5
     * C11 = U1
     * C12 = U5
     * C21 = U6
     * C22 = U7
     */
    //if (matA.shape[0] <= 1) {
    //    print_double_matrix(matC);
    //    matC.data[0][0] = matA.data[0][0] * matB.data[0][0];
    //    print_double_matrix(matC);
    //    return 0;
    //}

    if (!(matA.shape[0] == matA.shape[1] && matA.shape[1] == matB.shape[0] && matB.shape[0] == matB.shape[1] && matA.shape[0]%2==0)) {
        return -1;
    }
    int N = matA.shape[0];
    int II = matA.shape[0]/2;
    if (N <= 18000) {
        return matmul_double_blas(matC, matA, matB);
    }
    double_cmat A_x_1;
    double_cmat A_x_2;
    double_cmat B_x_1;
    double_cmat B_x_2;
    double_cmat C_x_1;
    double_cmat C_x_2;
    create_slice_double_matrix_contiguous(&A_x_1, matA, pairint { 0, N }, pairint { 0*II, 1*II });
    create_slice_double_matrix_contiguous(&A_x_2, matA, pairint { 0, N }, pairint { 1*II, 2*II });
    create_slice_double_matrix_contiguous(&B_x_1, matB, pairint { 0, N }, pairint { 0*II, 1*II });
    create_slice_double_matrix_contiguous(&B_x_2, matB, pairint { 0, N }, pairint { 1*II, 2*II });
    create_double_matrix(pairuint { N, II }, &C_x_1);
    create_double_matrix(pairuint { N, II }, &C_x_2);
    double_cmat A11 = slice_double_matrix(A_x_1, pairint {0,II}, pairint {0,II});
    double_cmat A12 = slice_double_matrix(A_x_2, pairint {0,II}, pairint {0,II});
    double_cmat A21 = slice_double_matrix(A_x_1, pairint {II,N}, pairint {0,II});
    double_cmat A22 = slice_double_matrix(A_x_2, pairint {II,N}, pairint {0,II});
    double_cmat B11 = slice_double_matrix(B_x_1, pairint {0,II}, pairint {0,II});
    double_cmat B12 = slice_double_matrix(B_x_2, pairint {0,II}, pairint {0,II});
    double_cmat B21 = slice_double_matrix(B_x_1, pairint {II,N}, pairint {0,II});
    double_cmat B22 = slice_double_matrix(B_x_2, pairint {II,N}, pairint {0,II});
    double_cmat C11 = slice_double_matrix(C_x_1, pairint {0,II}, pairint {0,II});
    double_cmat C12 = slice_double_matrix(C_x_2, pairint {0,II}, pairint {0,II});
    double_cmat C21 = slice_double_matrix(C_x_1, pairint {II,N}, pairint {0,II});
    double_cmat C22 = slice_double_matrix(C_x_2, pairint {II,N}, pairint {0,II});
    double_cmat S1, T1, M1, M2, M6, M7;
    create_double_matrix(pairuint {II,II}, &S1);
    create_double_matrix(pairuint {II,II}, &T1);
    create_double_matrix(pairuint {II,II}, &M1);
    create_double_matrix(pairuint {II,II}, &M2);
    create_double_matrix(pairuint {II,II}, &M6);
    create_double_matrix(pairuint {II,II}, &M7);


    matmul_double_strassen_winograd(M1, A11, B11);
    matmul_double_strassen_winograd(M2, A12, B21);

    matadd_double(S1, A21, A22);
    matsub_double(T1, B12, B11);
    matmul_double_strassen_winograd(C22, S1,  T1 );
    matsub_double(S1, S1,  A11);
    matsub_double(T1, B22, T1 );
    matmul_double_strassen_winograd(M6, S1,  T1 );
    matsub_double(T1, T1,  B21);
    matmul_double_strassen_winograd(C21, A22, T1 );
    matsub_double(S1, A12, S1 );
    matmul_double_strassen_winograd(C12, S1 , B22);
    matsub_double(S1, A11, A21);
    matsub_double(T1, B22, B12);
    matmul_double_strassen_winograd(M7, S1,  T1 );

    matadd_double(C11, M1, M2);
    matadd_double(M2, M1, M6);
    matadd_double(M6, M2, C22);
    matadd_double(C12, M6, C12);
    matadd_double(M2, M2, M7);
    matsub_double(C21, M2, C21);
    matadd_double(C22, M2, C22);

    assign_double_slice(matC, C_x_1, pairint {0, N}, pairint { 0*II, 1*II });
    assign_double_slice(matC, C_x_2, pairint {0, N}, pairint { 1*II, 2*II });

    free_double_matrix(S1);
    free_double_matrix(T1);
    free_double_matrix(M1);
    free_double_matrix(M2);
    free_double_matrix(M6);
    free_double_matrix(M7);

    free_double_matrix(A11);
    free_double_matrix(A12);
    free_double_matrix(A21);
    free_double_matrix(A22);
    free_double_matrix(B11);
    free_double_matrix(B12);
    free_double_matrix(B21);
    free_double_matrix(B22);
    free_double_matrix(C11);
    free_double_matrix(C12);
    free_double_matrix(C21);
    free_double_matrix(C22);
    free_double_matrix(A_x_1);
    free_double_matrix(A_x_2);
    free_double_matrix(B_x_1);
    free_double_matrix(B_x_2);
    free_double_matrix(C_x_1);
    free_double_matrix(C_x_2);
    return 0;
}

int matmul_double_schwartz2024(double_cmat matC, double_cmat matA, double_cmat matB){
    if (!(matA.shape[0] == matA.shape[1] && matA.shape[1] == matB.shape[0] && matB.shape[0] == matB.shape[1] && matA.shape[0]%2==0)) {
        return -1;
    }
    int N = matA.shape[0];
    int II = matA.shape[0]/2;
    int BN = II*II;
    if (N <= 18000) {
        return matmul_double_blas(matC, matA, matB);
    }
    double_cmat A_x_1;
    double_cmat A_x_2;
    double_cmat B_x_1;
    double_cmat B_x_2;
    double_cmat C_x_1;
    double_cmat C_x_2;
    create_slice_double_matrix_contiguous(&A_x_1, matA, pairint { 0, N }, pairint { 0*II, 1*II });
    create_slice_double_matrix_contiguous(&A_x_2, matA, pairint { 0, N }, pairint { 1*II, 2*II });
    create_slice_double_matrix_contiguous(&B_x_1, matB, pairint { 0, N }, pairint { 0*II, 1*II });
    create_slice_double_matrix_contiguous(&B_x_2, matB, pairint { 0, N }, pairint { 1*II, 2*II });
    create_double_matrix(pairuint { N, II }, &C_x_1);
    create_double_matrix(pairuint { N, II }, &C_x_2);
    double_cmat A11 = slice_double_matrix(A_x_1, pairint {0,II}, pairint {0,II});
    double_cmat A12 = slice_double_matrix(A_x_2, pairint {0,II}, pairint {0,II});
    double_cmat A21 = slice_double_matrix(A_x_1, pairint {II,N}, pairint {0,II});
    double_cmat A22 = slice_double_matrix(A_x_2, pairint {II,N}, pairint {0,II});
    double_cmat B11 = slice_double_matrix(B_x_1, pairint {0,II}, pairint {0,II});
    double_cmat B12 = slice_double_matrix(B_x_2, pairint {0,II}, pairint {0,II});
    double_cmat B21 = slice_double_matrix(B_x_1, pairint {II,N}, pairint {0,II});
    double_cmat B22 = slice_double_matrix(B_x_2, pairint {II,N}, pairint {0,II});
    double_cmat C11 = slice_double_matrix(C_x_1, pairint {0,II}, pairint {0,II});
    double_cmat C12 = slice_double_matrix(C_x_2, pairint {0,II}, pairint {0,II});
    double_cmat C21 = slice_double_matrix(C_x_1, pairint {II,N}, pairint {0,II});
    double_cmat C22 = slice_double_matrix(C_x_2, pairint {II,N}, pairint {0,II});
    // pa11 = a21 + a22
    // pa12 = a22
    // pa21 = -a11 - a12
    // pa22 = a11 + a22
    //
    // tmp1 = -a11
    // a11 = a21 + a22
    // a21 = tmp1 - a12
    // a12 = a22
    // tmp1 = -tmp1
    // a22 = tmp1 + a22
    //
    //
    // pb11 = b11
    // pb12 = b11 + b12
    // pb21 = b21 - b11
    // pb22 = b11 + b22
    double_cmat S5, T5, M1, M2, M3, M4, M5, M6, M7;
    create_double_matrix(pairuint {II,II}, &S5);
    create_double_matrix(pairuint {II,II}, &T5);
    create_double_matrix(pairuint {II,II}, &M1);
    create_double_matrix(pairuint {II,II}, &M2);
    create_double_matrix(pairuint {II,II}, &M3);
    create_double_matrix(pairuint {II,II}, &M4);
    create_double_matrix(pairuint {II,II}, &M5);
    create_double_matrix(pairuint {II,II}, &M6);
    create_double_matrix(pairuint {II,II}, &M7);


    // reuse M1 for tmp1, M2 for tmp2
    assign_double_clone(M2, A11);
    matneg_double(M1, A11);
    matadd_double(A11, A21, A22);
    matsub_double(A21, M1, A12);
    assign_double_clone(A12, A22);
    matadd_double(A22, M2, A22);
    memset(&M1.data[0][0], 0, sizeof(double)*BN);
    memset(&M2.data[0][0], 0, sizeof(double)*BN);

    matadd_double(B12, B11, B12);
    matsub_double(B21, B21, B11);
    matadd_double(B22, B11, B22);

    //printf("A\n");
    //print_double_matrix(matA);
    //printf("B\n");
    //print_double_matrix(matB);
    matadd_double(S5, A21, A22);
    matadd_double(T5, B21, B22);
    matmul_double_schwartz2024(M5, S5,  T5 );
    matsub_double(S5, A22, A12);
    matsub_double(T5, B22, B12);
    matmul_double_schwartz2024(M6, S5,  T5 );
    matsub_double(S5, A22, A11);
    matmul_double_schwartz2024(M7, S5,  B12);

    matsub_double(T5, B22, B11);
    matmul_double_schwartz2024(M3, A21, T5 );
    matmul_double_schwartz2024(M4, A22, B22);
    matmul_double_schwartz2024(M1, A11, B11);
    matmul_double_schwartz2024(M2, A12, B21);

    matadd_double(C11, M1, M2);
    matsub_double(C12, M5, M7);
    matadd_double(C21, M3, M6);
    matadd_double(C22, M5, M6);
    matsub_double(C22, C22, M2);
    matsub_double(C22, C22, M4);


    //printf("C\n");
    //print_double_matrix(matC);

    // c11 = pc21 - pc22
    // c12 = -pc21
    // c21 = pc11
    // c22 = pc12 - pc11 - pc22
    //
    // tmp1 = c21
    // c21 = c11
    // c11 = tmp1 - c22
    // c22 = c12 - c21 - c22
    // c12 = -tmp1
    assign_double_clone(M1, C21);
    assign_double_clone(C21, C11);
    matsub_double(C11, M1, C22);

    matneg_double(C22, C22);
    matadd_double(C22, C22, C12);
    matsub_double(C22, C22, C21);

    matneg_double(C12, M1);

    assign_double_slice(matC, C_x_1, pairint {0, N}, pairint { 0*II, 1*II });
    assign_double_slice(matC, C_x_2, pairint {0, N}, pairint { 1*II, 2*II });

    free_double_matrix(S5);
    free_double_matrix(T5);
    free_double_matrix(M1);
    free_double_matrix(M2);
    free_double_matrix(M3);
    free_double_matrix(M4);
    free_double_matrix(M5);
    free_double_matrix(M6);
    free_double_matrix(M7);
 
    free_double_matrix(A11);
    free_double_matrix(A12);
    free_double_matrix(A21);
    free_double_matrix(A22);
    free_double_matrix(B11);
    free_double_matrix(B12);
    free_double_matrix(B21);
    free_double_matrix(B22);
    free_double_matrix(C11);
    free_double_matrix(C12);
    free_double_matrix(C21);
    free_double_matrix(C22);

    free_double_matrix(A_x_1);
    free_double_matrix(A_x_2);
    free_double_matrix(B_x_1);
    free_double_matrix(B_x_2);
    free_double_matrix(C_x_1);
    free_double_matrix(C_x_2);
    return 0;
}

#ifdef MAIN_MATMUL

#include <time.h>

int main() {
    double_cmat A, B, C, TC;
    int N = 6000*2*2;
    create_double_matrix(pairuint {N, N}, &A);
    create_double_matrix(pairuint {N, N}, &B);
    create_double_matrix(pairuint {N, N}, &C);
    create_double_matrix(pairuint {N, N}, &TC);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.data[i][j] = 2.0 * rand() / RAND_MAX - 1;
            B.data[i][j] = 2.0 * rand() / RAND_MAX - 1;
        }
    }
    //printf("A:\n");
    //print_double_matrix(A);
    //printf("B:\n");
    //print_double_matrix(B);

    struct timespec start, end;
    double endtime;

    clock_gettime(CLOCK_MONOTONIC, &start);
    matmul_double_strassen_winograd(C, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("strassen winograd time: %f(s)\n", endtime);

    //clock_gettime(CLOCK_MONOTONIC, &start);
    //matmul_double_schwartz2024(C, A, B);
    //clock_gettime(CLOCK_MONOTONIC, &end);
    //endtime = (end.tv_sec - start.tv_sec) +
    //                      (end.tv_nsec - start.tv_nsec) / 1e9;
    //printf("schwartz 2024 time: %f(s)\n", endtime);

    //start = clock();
    //matmul_double_sse2(C, A, B);
    //end = clock();
    //endtime = (double) (end - start)/CLOCKS_PER_SEC;
    //printf("sse2 time: %f(s)\n", endtime);

    //printf("C:\n");
    //print_double_matrix(C);

    clock_gettime(CLOCK_MONOTONIC, &start);
    matmul_double_blas(TC, A, B);
    clock_gettime(CLOCK_MONOTONIC, &end);
    endtime = (end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("blas time: %f(s)\n", endtime);

    //printf("TC:\n");
    //print_double_matrix(TC);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fabs(C.data[i][j] - TC.data[i][j]) > 0.01) {
                printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
                return -1;
            }
        }
    }
    printf("finished\n");
    return 0;
}

#endif
