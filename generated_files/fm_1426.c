#include "stdafx.h"
#include "fm_1426.h"

int fm_1426(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_5, bmats.A_13_5, bmats.A_13_6, bmats.A_5_12, bmats.Ax2086, bmats.Ax4208, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_12_12, bmats.B_12_14, bmats.B_12_5, bmats.B_12_7, bmats.B_12_9, bmats.B_14_5, bmats.B_15_5, bmats.B_4_5, bmats.B_5_12, bmats.B_7_5, bmats.B_9_5, bmats.Bx11433, bmats.Bx6289, };
    double B_coeffs[13] = {-1, -1, -2, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
