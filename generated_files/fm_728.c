#include "stdafx.h"
#include "fm_728.h"

int fm_728(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_11_11, bmats.A_11_12, bmats.A_27_5, bmats.A_27_6, bmats.A_3_11, bmats.A_3_12, bmats.A_5_31, bmats.A_5_32, bmats.Ax2190, bmats.Ax2208, bmats.Ax2558, bmats.Ax2780, bmats.Ax781, };
    double A_coeffs[13] = {16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_11_21, bmats.B_17_11, bmats.B_18_11, bmats.B_19_11, bmats.B_20_11, bmats.B_21_11, bmats.B_22_11, bmats.B_23_11, bmats.B_24_11, bmats.B_25_11, bmats.B_26_11, bmats.B_27_11, bmats.B_28_11, bmats.B_29_11, bmats.B_30_11, bmats.B_31_11, bmats.B_32_11, bmats.B_5_1, bmats.B_5_10, bmats.B_5_11, bmats.B_5_12, bmats.B_5_13, bmats.B_5_14, bmats.B_5_15, bmats.B_5_16, bmats.B_5_2, bmats.B_5_3, bmats.B_5_4, bmats.B_5_5, bmats.B_5_6, bmats.B_5_7, bmats.B_5_8, bmats.B_5_9, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
