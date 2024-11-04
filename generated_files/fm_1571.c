#include "stdafx.h"
#include "fm_1571.h"

int fm_1571(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_25_14, bmats.A_4_10, bmats.A_4_9, bmats.Ax1532, bmats.Ax2935, bmats.Ax4329, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_13_4, bmats.B_14_4, bmats.B_15_4, bmats.B_16_4, bmats.B_1_4, bmats.B_20_9, bmats.B_2_4, bmats.B_3_4, bmats.B_5_4, bmats.B_6_4, bmats.B_9_4, bmats.Bx11903, bmats.Bx9527, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
