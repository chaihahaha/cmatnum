#include "stdafx.h"
#include "fm_1211.h"

int fm_1211(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_23_31, bmats.A_23_32, bmats.A_23_7, bmats.A_23_8, bmats.Ax3797, bmats.Ax618, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_7, bmats.B_18_7, bmats.B_19_7, bmats.B_20_7, bmats.B_21_7, bmats.B_22_7, bmats.B_23_23, bmats.B_23_7, bmats.B_24_7, bmats.B_25_7, bmats.B_26_7, bmats.B_27_7, bmats.B_28_7, bmats.B_29_7, bmats.B_30_7, bmats.B_31_7, bmats.B_32_7, bmats.B_7_17, bmats.B_7_18, bmats.B_7_19, bmats.B_7_20, bmats.B_7_21, bmats.B_7_22, bmats.B_7_23, bmats.B_7_24, bmats.B_7_25, bmats.B_7_26, bmats.B_7_27, bmats.B_7_28, bmats.B_7_29, bmats.B_7_30, bmats.B_7_31, bmats.B_7_32, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
