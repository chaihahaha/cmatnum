#include "stdafx.h"
#include "fm_1524.h"

int fm_1524(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_3, bmats.A_13_4, bmats.A_16_4, bmats.A_4_16, bmats.Ax2152, bmats.Ax4344, };
    double A_coeffs[6] = {1, -16, -17, 17, 1, 1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_13_4, bmats.B_14_4, bmats.B_15_4, bmats.B_16_1, bmats.B_16_10, bmats.B_16_11, bmats.B_16_12, bmats.B_16_13, bmats.B_16_14, bmats.B_16_15, bmats.B_16_16, bmats.B_16_2, bmats.B_16_3, bmats.B_16_4, bmats.B_16_5, bmats.B_16_6, bmats.B_16_7, bmats.B_16_8, bmats.B_16_9, bmats.B_1_4, bmats.B_2_4, bmats.B_3_4, bmats.B_4_16, bmats.B_5_4, bmats.B_6_4, bmats.B_9_4, bmats.Bx11903, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
