#include "stdafx.h"
#include "fm_1489.h"

int fm_1489(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_5_18, bmats.A_5_23, bmats.A_7_15, bmats.A_7_16, bmats.Ax4222, bmats.Ax573, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 22;
    double_cmat B_mats[22] = {bmats.B_15_21, bmats.B_16_21, bmats.B_1_21, bmats.B_23_10, bmats.B_23_11, bmats.B_23_12, bmats.B_23_13, bmats.B_23_14, bmats.B_23_15, bmats.B_23_16, bmats.B_23_7, bmats.B_23_8, bmats.B_23_9, bmats.B_2_21, bmats.B_3_21, bmats.B_4_21, bmats.B_5_21, bmats.B_5_7, bmats.B_7_21, bmats.B_9_21, bmats.Bx11066, bmats.Bx11440, };
    double B_coeffs[22] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_21.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
