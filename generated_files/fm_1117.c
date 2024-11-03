#include "fm_1117.h"
#include "stdafx.h"

inline int fm_1117(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_24_19, bmats.A_24_20, bmats.A_4_31, bmats.Ax105, bmats.Ax1587, bmats.Ax3419, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_24, bmats.B_18_24, bmats.B_19_24, bmats.B_20_1, bmats.B_20_10, bmats.B_20_11, bmats.B_20_12, bmats.B_20_13, bmats.B_20_14, bmats.B_20_15, bmats.B_20_16, bmats.B_20_2, bmats.B_20_24, bmats.B_20_3, bmats.B_20_4, bmats.B_20_5, bmats.B_20_6, bmats.B_20_7, bmats.B_20_8, bmats.B_20_9, bmats.B_21_24, bmats.B_22_24, bmats.B_23_24, bmats.B_24_24, bmats.B_25_24, bmats.B_26_24, bmats.B_27_24, bmats.B_28_24, bmats.B_29_24, bmats.B_30_24, bmats.B_31_24, bmats.B_32_24, bmats.B_8_20, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_24.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
