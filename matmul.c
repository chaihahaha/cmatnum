#include "matmul.h"

static int matmul_float(struct float_cmat matA, struct float_cmat matB, struct float_cmat matC){
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

static int matmul_double(struct double_cmat matA, struct double_cmat matB, struct double_cmat matC){
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

static int matmul_double_sse2(struct double_cmat matA, struct double_cmat matB, struct double_cmat matC){
    if (matA.shape[1] != matB.shape[0]) {
        return -1;
    }
    int M = matA.shape[0];
    int N = matB.shape[1];
    int K = matB.shape[0];
    if (M % 8 != 0 || N % 8 != 0 || K % 8 != 0) {
        return -1;
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

#ifdef MAIN_MATMUL

int main() {
    //struct float_cmat A;
    //float A_data[12] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12};
    //int A_offset[2] = {0,0};
    //create_float_matrix_from_stack(3,4,A_data, 12, A_offset, &A);

    //struct float_cmat B;
    //float B_data[8] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    //int B_offset[2] = {0,0};
    //create_float_matrix_from_stack(4,2,B_data, 8, B_offset, &B);

    //struct float_cmat C;
    //create_float_matrix(3,2, &C);
    //matmul_float(A, B, C);
    //print_float_matrix(C);

    struct double_cmat A;
    double A_data[96] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12};
    int A_offset[2] = {0,0};
    create_double_matrix_from_stack((int[2]){8,8},A_data, 64, A_offset, &A);

    struct double_cmat B;
    double B_data[160] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    int B_offset[2] = {0,0};
    create_double_matrix_from_stack((int[2]){8,16},B_data, 128, B_offset, &B);

    struct double_cmat C, D;
    create_double_matrix((int[2]){8,16}, &C);
    create_double_matrix((int[2]){8,16}, &D);
    matmul_double_sse2(A, B, C);
    matmul_double(A, B, D);
    print_double_matrix(C);
    print_double_matrix(D);
    return 0;
}

#endif
