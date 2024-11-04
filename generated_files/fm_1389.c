#include "stdafx.h"
#include "fm_1389.h"

int fm_1389(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_19_16, bmats.A_6_3, bmats.A_6_4, bmats.Ax3867, bmats.Ax4102, bmats.Ax962, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_14_6, bmats.B_15_6, bmats.B_16_6, bmats.B_1_6, bmats.B_22_3, bmats.B_2_6, bmats.B_3_17, bmats.B_3_18, bmats.B_3_19, bmats.B_3_20, bmats.B_3_21, bmats.B_3_22, bmats.B_3_23, bmats.B_3_24, bmats.B_3_25, bmats.B_3_26, bmats.B_3_27, bmats.B_3_28, bmats.B_3_29, bmats.B_3_30, bmats.B_3_31, bmats.B_3_32, bmats.B_3_6, bmats.B_4_6, bmats.B_5_6, bmats.Bx10888, };
    double B_coeffs[26] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
