#include "stdafx.h"
#include "fm_882.h"

int fm_882(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_4, bmats.A_3_10, bmats.A_3_9, bmats.A_4_10, bmats.Ax2932, bmats.Ax3117, };
    double A_coeffs[6] = {17, -16, 1, -17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_10, bmats.B_10_4, bmats.B_11_10, bmats.B_12_10, bmats.B_13_10, bmats.B_14_10, bmats.B_15_10, bmats.B_16_10, bmats.B_1_10, bmats.B_2_10, bmats.B_3_10, bmats.B_4_1, bmats.B_4_10, bmats.B_4_11, bmats.B_4_12, bmats.B_4_13, bmats.B_4_14, bmats.B_4_15, bmats.B_4_16, bmats.B_4_2, bmats.B_4_3, bmats.B_4_4, bmats.B_4_5, bmats.B_4_6, bmats.B_4_7, bmats.B_4_8, bmats.B_4_9, bmats.B_5_10, bmats.B_6_10, bmats.B_7_10, bmats.B_8_10, bmats.B_9_10, };
    double B_coeffs[32] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
