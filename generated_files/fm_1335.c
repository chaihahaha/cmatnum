#include "stdafx.h"
#include "fm_1335.h"

int fm_1335(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_6_9, bmats.A_8_5, bmats.A_8_6, bmats.A_9_6, bmats.Ax3541, bmats.Ax4013, };
    double A_coeffs[6] = {17, 1, -16, -17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_6, bmats.B_11_6, bmats.B_12_6, bmats.B_13_6, bmats.B_14_6, bmats.B_15_6, bmats.B_16_6, bmats.B_1_6, bmats.B_2_6, bmats.B_3_6, bmats.B_4_6, bmats.B_5_6, bmats.B_6_6, bmats.B_6_9, bmats.B_7_6, bmats.B_8_6, bmats.B_9_1, bmats.B_9_10, bmats.B_9_11, bmats.B_9_12, bmats.B_9_13, bmats.B_9_14, bmats.B_9_15, bmats.B_9_16, bmats.B_9_2, bmats.B_9_3, bmats.B_9_4, bmats.B_9_5, bmats.B_9_6, bmats.B_9_7, bmats.B_9_8, bmats.B_9_9, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
