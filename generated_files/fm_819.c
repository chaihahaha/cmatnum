#include "fm_819.h"
#include "stdafx.h"

inline int fm_819(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_10_10, bmats.A_10_9, bmats.A_1_10, bmats.A_1_9, bmats.A_26_7, bmats.A_26_8, bmats.A_8_31, bmats.A_8_32, bmats.Ax2941, bmats.Ax2956, bmats.Ax2958, bmats.Ax3002, bmats.Ax766, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_24, bmats.B_17_10, bmats.B_18_10, bmats.B_19_10, bmats.B_20_10, bmats.B_21_10, bmats.B_22_10, bmats.B_23_10, bmats.B_24_10, bmats.B_25_10, bmats.B_26_10, bmats.B_27_10, bmats.B_28_10, bmats.B_29_10, bmats.B_30_10, bmats.B_31_10, bmats.B_32_10, bmats.B_8_1, bmats.B_8_10, bmats.B_8_11, bmats.B_8_12, bmats.B_8_13, bmats.B_8_14, bmats.B_8_15, bmats.B_8_16, bmats.B_8_2, bmats.B_8_3, bmats.B_8_4, bmats.B_8_5, bmats.B_8_6, bmats.B_8_7, bmats.B_8_8, bmats.B_8_9, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_10.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
