#include "stdafx.h"
#include "fm_554.h"

int fm_554(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_12, bmats.A_11_11, bmats.A_11_12, bmats.A_12_10, bmats.Ax2190, bmats.Ax2396, };
    double A_coeffs[6] = {-17, 1, -16, 17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_1, bmats.B_10_10, bmats.B_10_11, bmats.B_10_12, bmats.B_10_13, bmats.B_10_14, bmats.B_10_15, bmats.B_10_16, bmats.B_10_2, bmats.B_10_3, bmats.B_10_4, bmats.B_10_5, bmats.B_10_6, bmats.B_10_7, bmats.B_10_8, bmats.B_10_9, bmats.B_11_12, bmats.B_12_10, bmats.B_12_12, bmats.B_13_12, bmats.B_14_12, bmats.B_15_12, bmats.B_16_12, bmats.B_1_12, bmats.B_2_12, bmats.B_3_12, bmats.B_4_12, bmats.B_5_12, bmats.B_6_12, bmats.B_7_12, bmats.B_8_12, bmats.B_9_12, };
    double B_coeffs[32] = {-1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
