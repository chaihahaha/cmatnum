#include "stdafx.h"
#include "fm_351.h"

int fm_351(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_23, bmats.A_14_24, bmats.A_17_29, bmats.A_17_30, bmats.A_23_15, bmats.A_23_16, bmats.A_30_29, bmats.A_30_30, bmats.Ax1076, bmats.Ax1120, bmats.Ax1130, bmats.Ax1427, bmats.Ax694, };
    double A_coeffs[13] = {16, -1, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_30, bmats.B_11_30, bmats.B_12_30, bmats.B_13_30, bmats.B_14_30, bmats.B_15_30, bmats.B_16_30, bmats.B_1_30, bmats.B_23_17, bmats.B_23_18, bmats.B_23_19, bmats.B_23_20, bmats.B_23_21, bmats.B_23_22, bmats.B_23_23, bmats.B_23_24, bmats.B_23_25, bmats.B_23_26, bmats.B_23_27, bmats.B_23_28, bmats.B_23_29, bmats.B_23_30, bmats.B_23_31, bmats.B_23_32, bmats.B_2_30, bmats.B_30_7, bmats.B_3_30, bmats.B_4_30, bmats.B_5_30, bmats.B_6_30, bmats.B_7_30, bmats.B_8_30, bmats.B_9_30, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
