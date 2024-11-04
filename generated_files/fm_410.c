#include "stdafx.h"
#include "fm_410.h"

int fm_410(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_31, bmats.A_29_27, bmats.A_29_28, bmats.Ax1309, bmats.Ax1867, bmats.Ax1966, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_13_28, bmats.B_17_29, bmats.B_18_29, bmats.B_19_29, bmats.B_20_29, bmats.B_21_29, bmats.B_22_29, bmats.B_23_29, bmats.B_24_29, bmats.B_25_29, bmats.B_26_29, bmats.B_27_29, bmats.B_28_1, bmats.B_28_10, bmats.B_28_11, bmats.B_28_12, bmats.B_28_13, bmats.B_28_14, bmats.B_28_15, bmats.B_28_16, bmats.B_28_2, bmats.B_28_29, bmats.B_28_3, bmats.B_28_4, bmats.B_28_5, bmats.B_28_6, bmats.B_28_7, bmats.B_28_8, bmats.B_28_9, bmats.B_29_29, bmats.B_30_29, bmats.B_31_29, bmats.B_32_29, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
