#include "cmat.h"
#include "fmm_3x3.h"

unsigned long fmm_3x3_fast_calls = 0;
unsigned long fmm_3x3_blas_calls = 0;

int fmm_3x3(double_cmat C, double_cmat A, double_cmat B) {
    shape_uint M = A.shape[0];
    shape_uint Kd = A.shape[1];
    shape_uint Nd = B.shape[1];
    if (B.shape[0] != Kd || C.shape[0] != M || C.shape[1] != Nd ||
        !(M % 3 == 0 && Kd % 3 == 0 && Nd % 3 == 0) ||
        M <= (shape_uint)fmm_base_block) {
        fmm_3x3_blas_calls++;
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    C.shape[0], C.shape[1], A.shape[1],
                    1.0, A.data[0], A.arena_shape[1],
                    B.data[0], B.arena_shape[1],
                    0.0, C.data[0], C.arena_shape[1]);
        return 0;
    }
    fmm_3x3_fast_calls++;
    const shape_uint BLHA = M / 3, BLWA = Kd / 3, BLHB = Kd / 3, BLWB = Nd / 3;
    const shape_uint BLHC = M / 3, BLWC = Nd / 3;
    const shape_uint NA = BLHA * BLWA, NB = BLHB * BLWB, NC = BLHC * BLWC;
    (void)NA; (void)NB; (void)NC;

    /*--- scratch blocks -------------------------------------------*/
    double_cmat scratch[5];
    create_double_matrix(pairuint {BLHA, BLWA}, &scratch[0]);
    create_double_matrix(pairuint {BLHA, BLWA}, &scratch[1]);
    create_double_matrix(pairuint {BLHB, BLWB}, &scratch[2]);
    create_double_matrix(pairuint {BLHB, BLWB}, &scratch[3]);
    create_double_matrix(pairuint {BLHA, BLWA}, &scratch[4]);

    double_cmat tmpA, tmpB, m;
    create_double_matrix(pairuint {BLHA, BLWA}, &tmpA);
    create_double_matrix(pairuint {BLHB, BLWB}, &tmpB);
    create_double_matrix(pairuint {BLHC, BLWC}, &m);

    /*--- macro-block views ----------------------------------------*/
    double_cmat A_x_1;
    double_cmat A_x_2;
    double_cmat A_x_3;
    double_cmat B_x_1;
    double_cmat C_x_1;
    double_cmat B_x_2;
    double_cmat C_x_2;
    double_cmat B_x_3;
    double_cmat C_x_3;
    create_slice_double_matrix_contiguous(&A_x_1, A, pairint {0, M}, pairint {0 * BLWA, 1 * BLWA});
    create_slice_double_matrix_contiguous(&A_x_2, A, pairint {0, M}, pairint {1 * BLWA, 2 * BLWA});
    create_slice_double_matrix_contiguous(&A_x_3, A, pairint {0, M}, pairint {2 * BLWA, 3 * BLWA});
    create_slice_double_matrix_contiguous(&B_x_1, B, pairint {0, Kd}, pairint {0 * BLWB, 1 * BLWB});
    create_double_matrix(pairuint {M, BLWC}, &C_x_1);
    create_slice_double_matrix_contiguous(&B_x_2, B, pairint {0, Kd}, pairint {1 * BLWB, 2 * BLWB});
    create_double_matrix(pairuint {M, BLWC}, &C_x_2);
    create_slice_double_matrix_contiguous(&B_x_3, B, pairint {0, Kd}, pairint {2 * BLWB, 3 * BLWB});
    create_double_matrix(pairuint {M, BLWC}, &C_x_3);
    double_cmat A_1_1 = slice_double_matrix(A_x_1, pairint {0 * BLHA, 1 * BLHA}, pairint {0, BLWA});
    double_cmat A_1_2 = slice_double_matrix(A_x_2, pairint {0 * BLHA, 1 * BLHA}, pairint {0, BLWA});
    double_cmat A_1_3 = slice_double_matrix(A_x_3, pairint {0 * BLHA, 1 * BLHA}, pairint {0, BLWA});
    double_cmat A_2_1 = slice_double_matrix(A_x_1, pairint {1 * BLHA, 2 * BLHA}, pairint {0, BLWA});
    double_cmat A_2_2 = slice_double_matrix(A_x_2, pairint {1 * BLHA, 2 * BLHA}, pairint {0, BLWA});
    double_cmat A_2_3 = slice_double_matrix(A_x_3, pairint {1 * BLHA, 2 * BLHA}, pairint {0, BLWA});
    double_cmat A_3_1 = slice_double_matrix(A_x_1, pairint {2 * BLHA, 3 * BLHA}, pairint {0, BLWA});
    double_cmat A_3_2 = slice_double_matrix(A_x_2, pairint {2 * BLHA, 3 * BLHA}, pairint {0, BLWA});
    double_cmat A_3_3 = slice_double_matrix(A_x_3, pairint {2 * BLHA, 3 * BLHA}, pairint {0, BLWA});
    double_cmat B_1_1 = slice_double_matrix(B_x_1, pairint {0 * BLHB, 1 * BLHB}, pairint {0, BLWB});
    double_cmat C_1_1 = slice_double_matrix(C_x_1, pairint {0 * BLHC, 1 * BLHC}, pairint {0, BLWC});
    double_cmat B_1_2 = slice_double_matrix(B_x_2, pairint {0 * BLHB, 1 * BLHB}, pairint {0, BLWB});
    double_cmat C_1_2 = slice_double_matrix(C_x_2, pairint {0 * BLHC, 1 * BLHC}, pairint {0, BLWC});
    double_cmat B_1_3 = slice_double_matrix(B_x_3, pairint {0 * BLHB, 1 * BLHB}, pairint {0, BLWB});
    double_cmat C_1_3 = slice_double_matrix(C_x_3, pairint {0 * BLHC, 1 * BLHC}, pairint {0, BLWC});
    double_cmat B_2_1 = slice_double_matrix(B_x_1, pairint {1 * BLHB, 2 * BLHB}, pairint {0, BLWB});
    double_cmat C_2_1 = slice_double_matrix(C_x_1, pairint {1 * BLHC, 2 * BLHC}, pairint {0, BLWC});
    double_cmat B_2_2 = slice_double_matrix(B_x_2, pairint {1 * BLHB, 2 * BLHB}, pairint {0, BLWB});
    double_cmat C_2_2 = slice_double_matrix(C_x_2, pairint {1 * BLHC, 2 * BLHC}, pairint {0, BLWC});
    double_cmat B_2_3 = slice_double_matrix(B_x_3, pairint {1 * BLHB, 2 * BLHB}, pairint {0, BLWB});
    double_cmat C_2_3 = slice_double_matrix(C_x_3, pairint {1 * BLHC, 2 * BLHC}, pairint {0, BLWC});
    double_cmat B_3_1 = slice_double_matrix(B_x_1, pairint {2 * BLHB, 3 * BLHB}, pairint {0, BLWB});
    double_cmat C_3_1 = slice_double_matrix(C_x_1, pairint {2 * BLHC, 3 * BLHC}, pairint {0, BLWC});
    double_cmat B_3_2 = slice_double_matrix(B_x_2, pairint {2 * BLHB, 3 * BLHB}, pairint {0, BLWB});
    double_cmat C_3_2 = slice_double_matrix(C_x_2, pairint {2 * BLHC, 3 * BLHC}, pairint {0, BLWC});
    double_cmat B_3_3 = slice_double_matrix(B_x_3, pairint {2 * BLHB, 3 * BLHB}, pairint {0, BLWB});
    double_cmat C_3_3 = slice_double_matrix(C_x_3, pairint {2 * BLHC, 3 * BLHC}, pairint {0, BLWC});

    /*--- scheduled evaluation -------------------------------------*/
    matlincomb_double_init(tmpA, 2, (double_cmat[]){A_3_2, A_3_1}, (double[]){-128.0, 16384.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_2_1, B_1_3}, (double[]){16384.0, 6.103515625e-05});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, -1.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -6.151199340820312e-05, m.data[0], 1, C_3_1.data[0], 1);
    cblas_daxpy(NC, 6.103515625e-05, m.data[0], 1, C_3_2.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(scratch[0], 2, (double_cmat[]){A_3_1, A_1_1}, (double[]){128.0, 0.0078125});
    matlincomb_double_init(tmpA, 4, (double_cmat[]){scratch[0], A_2_3, A_2_1, A_1_3}, (double[]){1.0, 1.0, -16384.0, -4.76837158203125e-07});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_3_1, B_1_3}, (double[]){16384.0, 0.0078125});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -0.00775146484375, m.data[0], 1, C_2_1.data[0], 1);
    matlincomb_double_init(scratch[1], 2, (double_cmat[]){A_3_2, A_3_1}, (double[]){-128.0, 16384.0});
    matlincomb_double_init(tmpA, 3, (double_cmat[]){scratch[1], A_1_1, A_1_2}, (double[]){-1.0, -1.0, 0.0078125});
    matlincomb_double_init(tmpB, 3, (double_cmat[]){B_2_1, B_3_1, B_1_1}, (double[]){1.0, 128.0, 0.0078125});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, -128.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, 3.725290298461914e-09, m.data[0], 1, C_3_1.data[0], 1);
    matlincomb_double_init(tmpA, 3, (double_cmat[]){scratch[1], A_1_2, A_1_1}, (double[]){1.0, -0.0001220703125, 0.0078125});
    matlincomb_double_init(tmpB, 3, (double_cmat[]){B_2_1, B_1_1, B_1_3}, (double[]){128.0, 0.0078125, 4.76837158203125e-07});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, -128.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, 0.0078125, m.data[0], 1, C_3_1.data[0], 1);
    matlincomb_double_init(scratch[2], 3, (double_cmat[]){B_1_1, B_2_1, B_3_1}, (double[]){1.0, 128.0, 16384.0});
    matlincomb_double_init(scratch[3], 2, (double_cmat[]){B_2_2, B_2_1}, (double[]){1.0, 128.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[3], B_1_3}, (double[]){1.0, 4.76837158203125e-07});
    fmm_3x3(m, A_3_2, tmpB);
    cblas_daxpy(NC, 128.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, -268435456.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 128.0, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_3_2.data[0], 1);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(tmpA, 3, (double_cmat[]){A_2_2, A_2_1, A_2_3}, (double[]){1.0, -128.0, 0.0078125});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_2_3, B_3_3}, (double[]){1.0, 128.0});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 6.103515625e-05, m.data[0], 1, C_2_2.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_2_3.data[0], 1);
    matlincomb_double_init(scratch[1], 2, (double_cmat[]){A_2_2, A_2_1}, (double[]){-1.0, 128.0});
    matlincomb_double_init(tmpA, 2, (double_cmat[]){scratch[1], A_3_2}, (double[]){-1.0, -16384.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[3], B_2_3}, (double[]){1.0, -6.103515625e-05});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 0.0078125, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 0.0078124962747097015, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_3_3, B_2_2}, (double[]){128.0, 0.0078125});
    fmm_3x3(m, scratch[1], tmpB);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, -2097152.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, -127.99993896484375, m.data[0], 1, C_2_2.data[0], 1);
    cblas_daxpy(NC, 128.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(tmpA, 4, (double_cmat[]){A_2_2, A_2_1, A_3_3, A_1_3}, (double[]){-128.0, 16384.0, -0.0078125, 4.76837158203125e-07});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_3_3, B_2_3}, (double[]){128.0, 4.76837158203125e-07});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, -0.0078125, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -0.0078125, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_2_2.data[0], 1);
    cblas_daxpy(NC, 0.0078125, m.data[0], 1, C_2_3.data[0], 1);
    cblas_daxpy(NC, -1.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(scratch[1], 2, (double_cmat[]){A_3_3, A_1_3}, (double[]){16384.0, -4.76837158203125e-07});
    matlincomb_double_init(tmpA, 2, (double_cmat[]){A_2_3, A_2_1}, (double[]){-1.0, 16384.0});
    matlincomb_double_init(tmpB, 3, (double_cmat[]){B_2_3, B_3_2, B_1_3}, (double[]){1.0, 1.0, 0.0078125});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -0.0078125, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, 0.0078125, m.data[0], 1, C_2_3.data[0], 1);
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_3_2, B_3_3}, (double[]){16384.0, -6.103515625e-05});
    fmm_3x3(m, A_3_3, tmpB);
    cblas_daxpy(NC, 2097152.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, -268435456.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -0.0078125, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_2_2.data[0], 1);
    cblas_daxpy(NC, -128.0, m.data[0], 1, C_2_3.data[0], 1);
    cblas_daxpy(NC, 6.103515625e-05, m.data[0], 1, C_3_2.data[0], 1);
    matlincomb_double_init(tmpA, 3, (double_cmat[]){A_2_1, A_3_3, A_2_3}, (double[]){-1.0, 16384.0, 6.103515625e-05});
    fmm_3x3(m, tmpA, B_3_2);
    cblas_daxpy(NC, 268435456.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_2_2.data[0], 1);
    cblas_daxpy(NC, 128.0, m.data[0], 1, C_2_3.data[0], 1);
    matlincomb_double_init(scratch[4], 3, (double_cmat[]){A_3_2, A_2_1, A_1_2}, (double[]){1.0, -16384.0, 6.103515625e-05});
    matlincomb_double_init(tmpA, 2, (double_cmat[]){scratch[4], A_2_3}, (double[]){1.0, 1.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){B_2_3, B_3_1}, (double[]){-1.0, 16384.0});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 0.0078125, m.data[0], 1, C_2_1.data[0], 1);
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[2], B_2_2}, (double[]){1.0, -1.0});
    fmm_3x3(m, scratch[4], tmpB);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_2.data[0], 1);
    matlincomb_double_init(scratch[4], 2, (double_cmat[]){A_3_1, A_3_2}, (double[]){-16384.0, 128.0});
    matlincomb_double_init(tmpA, 3, (double_cmat[]){scratch[4], A_2_1, A_2_2}, (double[]){-1.0, -1.0, 0.0078125});
    fmm_3x3(m, tmpA, B_2_1);
    cblas_daxpy(NC, -128.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, 268435456.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, 6.103515625e-05, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_3_3.data[0], 1);
    matlincomb_double_init(tmpA, 4, (double_cmat[]){scratch[4], A_1_1, A_1_2, A_1_3}, (double[]){1.0, -1.0, 0.0078125, 6.103515625e-05});
    fmm_3x3(m, tmpA, B_3_1);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_1.data[0], 1);
    cblas_daxpy(NC, 2097152.0, m.data[0], 1, C_1_3.data[0], 1);
    cblas_daxpy(NC, -1.0, m.data[0], 1, C_2_1.data[0], 1);
    matlincomb_double_init(scratch[3], 3, (double_cmat[]){B_3_2, B_1_2, B_3_3}, (double[]){128.0, 0.0078125, 4.76837158203125e-07});
    matlincomb_double_init(tmpA, 2, (double_cmat[]){scratch[1], A_2_1}, (double[]){1.0, 16384.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[2], scratch[3]}, (double[]){1.0, 1.0});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, -16384.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, 6.103515625e-05, m.data[0], 1, C_2_1.data[0], 1);
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[3], B_2_2}, (double[]){1.0, 1.0});
    fmm_3x3(m, A_2_1, tmpB);
    cblas_daxpy(NC, 268435456.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, 128.0, m.data[0], 1, C_2_2.data[0], 1);
    matlincomb_double_init(scratch[3], 2, (double_cmat[]){B_1_2, B_3_3}, (double[]){0.0078125, 9.5367431640625e-07});
    matlincomb_double_init(tmpA, 2, (double_cmat[]){scratch[1], scratch[0]}, (double[]){1.0, 1.0});
    matlincomb_double_init(tmpB, 2, (double_cmat[]){scratch[2], scratch[3]}, (double[]){1.0, 1.0});
    fmm_3x3(m, tmpA, tmpB);
    cblas_daxpy(NC, 16384.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, -6.103515625e-05, m.data[0], 1, C_2_1.data[0], 1);
    cblas_daxpy(NC, 3.725290298461914e-09, m.data[0], 1, C_3_1.data[0], 1);
    matlincomb_double_init(tmpB, 3, (double_cmat[]){scratch[3], B_2_1, B_1_3}, (double[]){-1.0, 128.0, 4.76837158203125e-07});
    fmm_3x3(m, A_3_1, tmpB);
    cblas_daxpy(NC, 2097152.0, m.data[0], 1, C_1_2.data[0], 1);
    cblas_daxpy(NC, 1.0, m.data[0], 1, C_3_1.data[0], 1);
    cblas_daxpy(NC, -128.0, m.data[0], 1, C_3_2.data[0], 1);

    /*--- write back ------------------------------------------------*/
    assign_double_slice(C, C_x_1, pairint {0, M}, pairint {0 * BLWC, 1 * BLWC});
    assign_double_slice(C, C_x_2, pairint {0, M}, pairint {1 * BLWC, 2 * BLWC});
    assign_double_slice(C, C_x_3, pairint {0, M}, pairint {2 * BLWC, 3 * BLWC});

    free_double_matrix(A_x_1);
    free_double_matrix(A_x_2);
    free_double_matrix(A_x_3);
    free_double_matrix(B_x_1);
    free_double_matrix(C_x_1);
    free_double_matrix(B_x_2);
    free_double_matrix(C_x_2);
    free_double_matrix(B_x_3);
    free_double_matrix(C_x_3);
    free_double_matrix(scratch[0]);
    free_double_matrix(scratch[1]);
    free_double_matrix(scratch[2]);
    free_double_matrix(scratch[3]);
    free_double_matrix(scratch[4]);
    free_double_matrix(tmpA);
    free_double_matrix(tmpB);
    free_double_matrix(m);
    return 0;
}
