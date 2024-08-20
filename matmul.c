#include "matmul.h"

static int matmul_float(float_cmat matA, float_cmat matB, float_cmat matC){
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

static int matmul_double(double_cmat matA, double_cmat matB, double_cmat matC){
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

static int matmul_double_sse2(double_cmat matA, double_cmat matB, double_cmat matC){
    if (matA.shape[1] != matB.shape[0]) {
        return -1;
    }
    int M = matA.shape[0];
    int N = matB.shape[1];
    int K = matB.shape[0];
    if (M % 8 != 0 || N % 8 != 0 || K % 8 != 0) {
        return matmul_double(matA, matB, matC);
    }
    int i, j, k, i2, j2, k2;
    double *restrict rC;
    double *restrict rA;
    double *restrict rB;
    for(i = 0; i < M; i+=SM) {
        for(j = 0; j < N; j+=SM) {
            for(k = 0; k < K; k+=SM) {
                for (i2 = 0, rC = &matC.data[i][j], rA = &matA.data[i][k]; i2 < SM; i2++, rC += N, rA += K)
                {
                    //printf("Processing row %d\n", i + i2); // Debug print
                    _mm_prefetch(&rA[8], _MM_HINT_NTA);
                    for (k2 = 0, rB = &matB.data[k][j]; k2 < SM; k2++, rB += N)
                    {
                        __m128d mAd = _mm_load_sd(&rA[k2]);
                        mAd = _mm_unpacklo_pd(mAd, mAd);
                        for (j2 = 0; j2 < SM; j2 += 2)
                        {
                            __m128d mB = _mm_load_pd(&rB[j2]);
                            __m128d mC = _mm_load_pd(&rC[j2]);
                            _mm_store_pd(&rC[j2], _mm_add_pd(_mm_mul_pd(mB, mAd), mC));

                            __m128d mResult = _mm_add_pd(_mm_mul_pd(mB, mAd), mC);
                            //printf("Row %d, Col %d-%d: %lf %lf\n", i + i2, j + j2, j + j2 + 1, ((double*)&mResult)[0], ((double*)&mResult)[1]); // Debug print
                        }
                    }
                }
            }
        }
    }
    return 0;
}

static int matmul_double_strassen_winograd(double_cmat matA, double_cmat matB, double_cmat matC){
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
    int I = matA.shape[0]/2;
    if (N <= 2) {
        return matmul_double_sse2(matA, matB, matC);
    }
    double_cmat A11 = slice_double_matrix(matA, (int[2]){0,I}, (int[2]){0,I});
    double_cmat A12 = slice_double_matrix(matA, (int[2]){0,I}, (int[2]){I,N});
    double_cmat A21 = slice_double_matrix(matA, (int[2]){I,N}, (int[2]){0,I});
    double_cmat A22 = slice_double_matrix(matA, (int[2]){I,N}, (int[2]){I,N});
    double_cmat B11 = slice_double_matrix(matB, (int[2]){0,I}, (int[2]){0,I});
    double_cmat B12 = slice_double_matrix(matB, (int[2]){0,I}, (int[2]){I,N});
    double_cmat B21 = slice_double_matrix(matB, (int[2]){I,N}, (int[2]){0,I});
    double_cmat B22 = slice_double_matrix(matB, (int[2]){I,N}, (int[2]){I,N});
    double_cmat S1, S2, S3, S4, T1, T2, T3, T4, M1, M2, M3, M4, M5, M6, M7, U1, U2, U3, U4, U5, U6, U7;
    create_double_matrix((int[2]){I,I}, &S1);
    create_double_matrix((int[2]){I,I}, &S2);
    create_double_matrix((int[2]){I,I}, &S3);
    create_double_matrix((int[2]){I,I}, &S4);
    create_double_matrix((int[2]){I,I}, &T1);
    create_double_matrix((int[2]){I,I}, &T2);
    create_double_matrix((int[2]){I,I}, &T3);
    create_double_matrix((int[2]){I,I}, &T4);
    create_double_matrix((int[2]){I,I}, &M1);
    create_double_matrix((int[2]){I,I}, &M2);
    create_double_matrix((int[2]){I,I}, &M3);
    create_double_matrix((int[2]){I,I}, &M4);
    create_double_matrix((int[2]){I,I}, &M5);
    create_double_matrix((int[2]){I,I}, &M6);
    create_double_matrix((int[2]){I,I}, &M7);
    create_double_matrix((int[2]){I,I}, &U1);
    create_double_matrix((int[2]){I,I}, &U2);
    create_double_matrix((int[2]){I,I}, &U3);
    create_double_matrix((int[2]){I,I}, &U4);
    create_double_matrix((int[2]){I,I}, &U5);
    create_double_matrix((int[2]){I,I}, &U6);
    create_double_matrix((int[2]){I,I}, &U7);
    matadd_double(A21, A22, S1);
    matsub_double(S1,  A11, S2);
    matsub_double(A11, A21, S3);
    matsub_double(A12, S2 , S4);

    matsub_double(B12, B11, T1);
    matsub_double(B22, T1 , T2);
    matsub_double(B22, B12, T3);
    matsub_double(T2,  B21, T4);

    matmul_double_strassen_winograd(A11, B11, M1);
    matmul_double_strassen_winograd(A12, B21, M2);
    matmul_double_strassen_winograd(S4 , B22, M3);
    matmul_double_strassen_winograd(A22, T4 , M4);
    matmul_double_strassen_winograd(S1,  T1 , M5);
    matmul_double_strassen_winograd(S2,  T2 , M6);
    matmul_double_strassen_winograd(S3,  T3 , M7);

    matadd_double(M1, M2, U1);
    matadd_double(M1, M6, U2);
    matadd_double(U2, M7, U3);
    matadd_double(U2, M5, U4);
    matadd_double(U4, M3, U5);
    matsub_double(U3, M4, U6);
    matadd_double(U3, M5, U7);

    assign_double_slice(matC, U1, (int[2]){0,I}, (int[2]){0,I});
    assign_double_slice(matC, U5, (int[2]){0,I}, (int[2]){I,N});
    assign_double_slice(matC, U6, (int[2]){I,N}, (int[2]){0,I});
    assign_double_slice(matC, U7, (int[2]){I,N}, (int[2]){I,N});

    free_double_matrix(S1);
    free_double_matrix(S2);
    free_double_matrix(S3);
    free_double_matrix(S4);
    free_double_matrix(T1);
    free_double_matrix(T2);
    free_double_matrix(T3);
    free_double_matrix(T4);
    free_double_matrix(M1);
    free_double_matrix(M2);
    free_double_matrix(M3);
    free_double_matrix(M4);
    free_double_matrix(M5);
    free_double_matrix(M6);
    free_double_matrix(M7);
    free_double_matrix(U1);
    free_double_matrix(U2);
    free_double_matrix(U3);
    free_double_matrix(U4);
    free_double_matrix(U5);
    free_double_matrix(U6);
    free_double_matrix(U7);
    return 0;
}

static int matmul_double_schwartz2024(double_cmat matA, double_cmat matB, double_cmat matC){
    return 0;
}
#ifdef MAIN_MATMUL

#include <time.h>

int main() {
    //float_cmat A;
    //float A_data[12] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12};
    //int A_offset[2] = {0,0};
    //create_float_matrix_from_array(3,4,A_data, 12, A_offset, &A);

    //float_cmat B;
    //float B_data[8] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    //int B_offset[2] = {0,0};
    //create_float_matrix_from_array(4,2,B_data, 8, B_offset, &B);

    //float_cmat C;
    //create_float_matrix(3,2, &C);
    //matmul_float(A, B, C);
    //print_float_matrix(C);

    //double_cmat A;
    //double A_data[96] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12};
    //int A_offset[2] = {0,0};
    //create_double_matrix_from_array((int[2]){8,8},A_data, 64, A_offset, &A);

    //double_cmat B;
    //double B_data[160] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    //int B_offset[2] = {0,0};
    //create_double_matrix_from_array((int[2]){8,16},B_data, 128, B_offset, &B);

    //double_cmat C, D;
    //create_double_matrix((int[2]){8,16}, &C);
    //create_double_matrix((int[2]){8,16}, &D);
    //matmul_double_sse2(A, B, C);
    //matmul_double(A, B, D);
    //print_double_matrix(C);
    //print_double_matrix(D);

    double_cmat A, B, C, TC;
    int N = 1024;
    create_double_matrix((int[2]){N, N}, &A);
    create_double_matrix((int[2]){N, N}, &B);
    create_double_matrix((int[2]){N, N}, &C);
    create_double_matrix((int[2]){N, N}, &TC);
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

    clock_t start, end;
    start = clock();
    matmul_double_strassen_winograd(A, B, C);
    end = clock();
    double endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("strassen winograd time: %f(s)\n", endtime);

    //printf("C:\n");
    //print_double_matrix(C);

    start = clock();
    matmul_double(A, B, TC);
    end = clock();
    endtime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("naive time: %f(s)\n", endtime);

    //printf("TC:\n");
    //print_double_matrix(TC);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(C.data[i][j] - TC.data[i][j]) > 0.0001) {
                printf("wrong: %lf, true: %lf, at: %d-%d\n", C.data[i][j], TC.data[i][j], i, j);
            }
        }
    }
    printf("finished\n");
    return 0;
}

#endif
