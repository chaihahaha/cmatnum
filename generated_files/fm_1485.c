#include "stdafx.h"
#include "fm_1485.h"

int fm_1485(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_21_7, bmats.A_21_8, bmats.A_2_5, bmats.A_2_6, bmats.A_5_5, bmats.A_5_6, bmats.A_7_31, bmats.A_7_32, bmats.Ax3408, bmats.Ax3914, bmats.Ax3920, bmats.Ax4174, bmats.Ax763, };
    double A_coeffs[13] = {16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_17_5, bmats.B_18_5, bmats.B_19_5, bmats.B_20_5, bmats.B_21_5, bmats.B_28_5, bmats.B_30_5, bmats.B_31_5, bmats.B_32_5, bmats.B_5_23, bmats.B_7_1, bmats.B_7_10, bmats.B_7_11, bmats.B_7_12, bmats.B_7_13, bmats.B_7_14, bmats.B_7_15, bmats.B_7_16, bmats.B_7_2, bmats.B_7_3, bmats.B_7_4, bmats.B_7_5, bmats.B_7_6, bmats.B_7_7, bmats.B_7_8, bmats.B_7_9, bmats.Bx11450, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
