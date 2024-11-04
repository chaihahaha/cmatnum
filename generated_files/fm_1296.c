#include "stdafx.h"
#include "fm_1296.h"

int fm_1296(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_16_31, bmats.A_16_32, bmats.A_1_5, bmats.A_1_6, bmats.A_22_15, bmats.A_22_16, bmats.A_6_5, bmats.A_6_6, bmats.Ax3917, bmats.Ax3953, bmats.Ax3955, bmats.Ax715, bmats.Ax751, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_16_1, bmats.B_16_10, bmats.B_16_11, bmats.B_16_12, bmats.B_16_13, bmats.B_16_14, bmats.B_16_15, bmats.B_16_16, bmats.B_16_2, bmats.B_16_3, bmats.B_16_4, bmats.B_16_5, bmats.B_16_6, bmats.B_16_7, bmats.B_16_8, bmats.B_16_9, bmats.B_17_6, bmats.B_18_6, bmats.B_19_6, bmats.B_20_6, bmats.B_21_6, bmats.B_22_6, bmats.B_31_6, bmats.B_32_6, bmats.B_6_32, bmats.Bx10674, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
