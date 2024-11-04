#include "stdafx.h"
#include "fm_15135.h"

int fm_15135(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_12_16, bmats.A_16_12, bmats.A_16_16, bmats.Ax7791, };
    double A_coeffs[4] = {-17, 17, -17, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_10_16, bmats.B_12_1, bmats.B_12_10, bmats.B_12_11, bmats.B_12_12, bmats.B_12_13, bmats.B_12_14, bmats.B_12_15, bmats.B_12_16, bmats.B_12_2, bmats.B_12_3, bmats.B_12_4, bmats.B_12_5, bmats.B_12_6, bmats.B_12_7, bmats.B_12_8, bmats.B_12_9, bmats.B_15_16, bmats.B_16_12, bmats.B_1_16, bmats.B_2_16, bmats.B_3_16, bmats.B_5_16, bmats.B_8_16, bmats.B_9_16, bmats.Bx13355, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
