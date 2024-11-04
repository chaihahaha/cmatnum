#include "stdafx.h"
#include "fm_255.h"

int fm_255(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_13, bmats.A_14_14, bmats.A_29_14, bmats.Ax443, bmats.Ax965, bmats.Ax983, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_14, bmats.B_11_14, bmats.B_12_14, bmats.B_13_14, bmats.B_13_17, bmats.B_13_18, bmats.B_13_19, bmats.B_13_20, bmats.B_13_21, bmats.B_13_22, bmats.B_13_23, bmats.B_13_24, bmats.B_13_25, bmats.B_13_26, bmats.B_13_27, bmats.B_13_28, bmats.B_13_29, bmats.B_13_30, bmats.B_13_31, bmats.B_13_32, bmats.B_14_14, bmats.B_15_14, bmats.B_16_14, bmats.B_1_14, bmats.B_2_14, bmats.B_30_13, bmats.B_3_14, bmats.B_4_14, bmats.B_5_14, bmats.B_6_14, bmats.B_7_14, bmats.B_8_14, bmats.B_9_14, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
