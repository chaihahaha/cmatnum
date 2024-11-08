#include "stdafx.h"
#include "fm_1394.h"

int fm_1394(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_1_5, bmats.A_1_6, bmats.A_22_3, bmats.A_22_4, bmats.A_4_31, bmats.A_4_32, bmats.A_6_5, bmats.A_6_6, bmats.Ax3917, bmats.Ax3953, bmats.Ax3955, bmats.Ax4096, bmats.Ax778, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_6, bmats.B_18_6, bmats.B_19_6, bmats.B_20_6, bmats.B_21_6, bmats.B_22_6, bmats.B_31_6, bmats.B_32_6, bmats.B_4_1, bmats.B_4_10, bmats.B_4_11, bmats.B_4_12, bmats.B_4_13, bmats.B_4_14, bmats.B_4_15, bmats.B_4_16, bmats.B_4_2, bmats.B_4_3, bmats.B_4_4, bmats.B_4_5, bmats.B_4_6, bmats.B_4_7, bmats.B_4_8, bmats.B_4_9, bmats.B_6_20, bmats.Bx10674, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
