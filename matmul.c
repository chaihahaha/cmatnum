#include "matmul.h"

static int matmul(struct FloatCMat matA, struct FloatCMat matB, struct FloatCMat matC){
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

int main() {
    struct FloatCMat A;
    float A_data[12] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12};
    int A_offset[2] = {0,0};
    create_float_matrix_from_stack(3,4,A_data, 12, A_offset, &A);

    struct FloatCMat B;
    float B_data[8] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    int B_offset[2] = {0,0};
    create_float_matrix_from_stack(4,2,B_data, 8, B_offset, &B);

    struct FloatCMat C;
    create_float_matrix(3,2, &C);
    matmul(A, B, C);
    print_float_matrix(C);
    return 0;
}
