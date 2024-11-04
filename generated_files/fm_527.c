#include "stdafx.h"
#include "fm_527.h"

int fm_527(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_15, bmats.A_12_16, bmats.A_12_28, bmats.A_12_32, bmats.Ax2337, bmats.Ax565, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_28, bmats.B_11_28, bmats.B_12_12, bmats.B_12_28, bmats.B_13_28, bmats.B_14_28, bmats.B_15_28, bmats.B_16_28, bmats.B_1_28, bmats.B_28_1, bmats.B_28_10, bmats.B_28_11, bmats.B_28_12, bmats.B_28_13, bmats.B_28_14, bmats.B_28_15, bmats.B_28_16, bmats.B_28_2, bmats.B_28_3, bmats.B_28_4, bmats.B_28_5, bmats.B_28_6, bmats.B_28_7, bmats.B_28_8, bmats.B_28_9, bmats.B_2_28, bmats.B_3_28, bmats.B_4_28, bmats.B_5_28, bmats.B_6_28, bmats.B_7_28, bmats.B_8_28, bmats.B_9_28, };
    double B_coeffs[33] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
