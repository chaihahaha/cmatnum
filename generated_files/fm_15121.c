#include "stdafx.h"
#include "fm_15121.h"

int fm_15121(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_10_31, bmats.A_10_32, bmats.A_12_15, bmats.A_12_16, bmats.A_16_15, bmats.A_16_16, bmats.A_32_10, bmats.A_32_9, bmats.Ax2801, bmats.Ax463, bmats.Ax565, bmats.Ax772, bmats.Ax7791, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_10_1, bmats.B_10_10, bmats.B_10_11, bmats.B_10_12, bmats.B_10_13, bmats.B_10_14, bmats.B_10_15, bmats.B_10_16, bmats.B_10_2, bmats.B_10_3, bmats.B_10_4, bmats.B_10_5, bmats.B_10_6, bmats.B_10_7, bmats.B_10_8, bmats.B_10_9, bmats.B_16_26, bmats.B_31_16, bmats.B_32_16, bmats.Bx13360, };
    double B_coeffs[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
