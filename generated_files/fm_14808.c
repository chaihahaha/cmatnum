#include "stdafx.h"
#include "fm_14808.h"

int fm_14808(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_10_31, bmats.A_10_32, bmats.A_15_15, bmats.A_15_16, bmats.A_16_15, bmats.A_16_16, bmats.A_31_10, bmats.A_31_9, bmats.Ax2804, bmats.Ax463, bmats.Ax649, bmats.Ax654, bmats.Ax772, };
    double A_coeffs[13] = {-1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_10_1, bmats.B_10_10, bmats.B_10_11, bmats.B_10_12, bmats.B_10_13, bmats.B_10_14, bmats.B_10_15, bmats.B_10_16, bmats.B_10_2, bmats.B_10_3, bmats.B_10_4, bmats.B_10_5, bmats.B_10_6, bmats.B_10_7, bmats.B_10_8, bmats.B_10_9, bmats.B_15_26, bmats.Bx13385, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
