#include "stdafx.h"
#include "fm_706.h"

int fm_706(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_27_23, bmats.A_27_24, bmats.A_8_31, bmats.Ax1449, bmats.Ax2598, bmats.Ax79, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_11_24, bmats.B_17_27, bmats.B_18_27, bmats.B_19_27, bmats.B_20_27, bmats.B_21_27, bmats.B_22_27, bmats.B_23_27, bmats.B_24_1, bmats.B_24_10, bmats.B_24_11, bmats.B_24_12, bmats.B_24_13, bmats.B_24_14, bmats.B_24_15, bmats.B_24_16, bmats.B_24_2, bmats.B_24_27, bmats.B_24_3, bmats.B_24_4, bmats.B_24_5, bmats.B_24_6, bmats.B_24_7, bmats.B_24_8, bmats.B_24_9, bmats.B_25_27, bmats.B_26_27, bmats.B_27_27, bmats.B_28_27, bmats.B_29_27, bmats.B_30_27, bmats.B_31_27, bmats.B_32_27, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
