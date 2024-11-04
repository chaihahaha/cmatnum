#include "stdafx.h"
#include "fm_1272.h"

int fm_1272(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_19_15, bmats.A_19_16, bmats.A_19_23, bmats.A_19_24, bmats.A_23_23, bmats.A_23_24, bmats.A_7_19, bmats.A_7_20, bmats.Ax343, bmats.Ax357, bmats.Ax3669, bmats.Ax3810, bmats.Ax706, };
    double A_coeffs[13] = {-1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 28;
    double_cmat B_mats[28] = {bmats.B_12_23, bmats.B_13_23, bmats.B_15_23, bmats.B_16_23, bmats.B_19_17, bmats.B_19_18, bmats.B_19_19, bmats.B_19_20, bmats.B_19_21, bmats.B_19_22, bmats.B_19_23, bmats.B_19_24, bmats.B_19_25, bmats.B_19_26, bmats.B_19_27, bmats.B_19_28, bmats.B_19_29, bmats.B_19_30, bmats.B_19_31, bmats.B_19_32, bmats.B_1_23, bmats.B_23_3, bmats.B_2_23, bmats.B_3_23, bmats.B_4_23, bmats.B_5_23, bmats.B_6_23, bmats.Bx10243, };
    double B_coeffs[28] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
