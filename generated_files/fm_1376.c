#include "stdafx.h"
#include "fm_1376.h"

int fm_1376(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_2_6, bmats.A_6_2, bmats.A_7_5, bmats.A_7_6, bmats.Ax3828, bmats.Ax4070, };
    double A_coeffs[6] = {-17, 17, 1, -16, 1, 1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_14_6, bmats.B_15_6, bmats.B_16_6, bmats.B_1_6, bmats.B_2_1, bmats.B_2_10, bmats.B_2_11, bmats.B_2_12, bmats.B_2_13, bmats.B_2_14, bmats.B_2_15, bmats.B_2_16, bmats.B_2_2, bmats.B_2_3, bmats.B_2_4, bmats.B_2_5, bmats.B_2_6, bmats.B_2_7, bmats.B_2_8, bmats.B_2_9, bmats.B_3_6, bmats.B_4_6, bmats.B_5_6, bmats.B_6_2, bmats.Bx10888, };
    double B_coeffs[25] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
