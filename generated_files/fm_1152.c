#include "stdafx.h"
#include "fm_1152.h"

int fm_1152(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_2_15, bmats.A_2_16, bmats.A_8_17, bmats.A_8_18, bmats.A_8_19, bmats.A_8_20, bmats.A_8_21, bmats.A_8_22, bmats.A_8_23, bmats.A_8_24, bmats.A_8_25, bmats.A_8_26, bmats.A_8_27, bmats.A_8_28, bmats.A_8_29, bmats.A_8_30, bmats.A_8_31, bmats.A_8_32, bmats.Ax3419, bmats.Ax556, };
    double A_coeffs[20] = {-1, -1, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_24, bmats.B_11_24, bmats.B_12_24, bmats.B_13_24, bmats.B_14_24, bmats.B_15_24, bmats.B_16_24, bmats.B_18_1, bmats.B_18_10, bmats.B_18_11, bmats.B_18_12, bmats.B_18_13, bmats.B_18_14, bmats.B_18_15, bmats.B_18_16, bmats.B_18_2, bmats.B_18_3, bmats.B_18_4, bmats.B_18_5, bmats.B_18_6, bmats.B_18_7, bmats.B_18_8, bmats.B_18_9, bmats.B_1_24, bmats.B_2_24, bmats.B_3_24, bmats.B_4_24, bmats.B_5_24, bmats.B_6_24, bmats.B_7_24, bmats.B_8_2, bmats.B_8_24, bmats.B_9_24, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
