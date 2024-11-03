#include "fm_440.h"
#include "stdafx.h"

inline int fm_440(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_10_31, bmats.A_10_32, bmats.A_13_13, bmats.A_13_14, bmats.A_29_10, bmats.A_29_9, bmats.A_2_13, bmats.A_2_14, bmats.Ax1027, bmats.Ax1054, bmats.Ax1939, bmats.Ax2044, bmats.Ax772, };
    double A_coeffs[13] = {-1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_1, bmats.B_10_10, bmats.B_10_11, bmats.B_10_12, bmats.B_10_13, bmats.B_10_14, bmats.B_10_15, bmats.B_10_16, bmats.B_10_2, bmats.B_10_3, bmats.B_10_4, bmats.B_10_5, bmats.B_10_6, bmats.B_10_7, bmats.B_10_8, bmats.B_10_9, bmats.B_13_26, bmats.B_17_13, bmats.B_18_13, bmats.B_19_13, bmats.B_20_13, bmats.B_21_13, bmats.B_22_13, bmats.B_23_13, bmats.B_24_13, bmats.B_25_13, bmats.B_26_13, bmats.B_27_13, bmats.B_28_13, bmats.B_29_13, bmats.B_30_13, bmats.B_31_13, bmats.B_32_13, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_13.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
