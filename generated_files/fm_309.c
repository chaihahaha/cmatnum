#include "stdafx.h"
#include "fm_309.h"

int fm_309(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_13, bmats.A_14_14, bmats.A_1_13, bmats.A_1_14, bmats.A_30_7, bmats.A_30_8, bmats.A_8_31, bmats.A_8_32, bmats.Ax1012, bmats.Ax1056, bmats.Ax1422, bmats.Ax766, bmats.Ax965, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_14_24, bmats.B_17_14, bmats.B_18_14, bmats.B_19_14, bmats.B_20_14, bmats.B_21_14, bmats.B_22_14, bmats.B_23_14, bmats.B_24_14, bmats.B_25_14, bmats.B_26_14, bmats.B_27_14, bmats.B_28_14, bmats.B_29_14, bmats.B_30_14, bmats.B_31_14, bmats.B_32_14, bmats.B_8_1, bmats.B_8_10, bmats.B_8_11, bmats.B_8_12, bmats.B_8_13, bmats.B_8_14, bmats.B_8_15, bmats.B_8_16, bmats.B_8_2, bmats.B_8_3, bmats.B_8_4, bmats.B_8_5, bmats.B_8_6, bmats.B_8_7, bmats.B_8_8, bmats.B_8_9, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
