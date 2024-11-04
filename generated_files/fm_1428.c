#include "stdafx.h"
#include "fm_1428.h"

int fm_1428(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_31, bmats.A_12_32, bmats.A_21_11, bmats.A_21_12, bmats.A_2_5, bmats.A_2_6, bmats.A_5_5, bmats.A_5_6, bmats.Ax2254, bmats.Ax3914, bmats.Ax3920, bmats.Ax4174, bmats.Ax757, };
    double A_coeffs[13] = {-1, -1, -1, 16, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_12_12, bmats.B_12_14, bmats.B_12_5, bmats.B_12_7, bmats.B_12_9, bmats.B_17_5, bmats.B_18_5, bmats.B_19_5, bmats.B_20_5, bmats.B_21_5, bmats.B_28_5, bmats.B_30_5, bmats.B_31_5, bmats.B_32_5, bmats.B_5_28, bmats.Bx11450, bmats.Bx6289, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
