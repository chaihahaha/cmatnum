#include "fm_329.h"
#include "stdafx.h"

inline int fm_329(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_3, bmats.A_14_4, bmats.A_20_15, bmats.Ax1590, bmats.Ax1608, bmats.Ax443, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_14, bmats.B_11_14, bmats.B_12_14, bmats.B_13_14, bmats.B_14_14, bmats.B_15_14, bmats.B_16_14, bmats.B_1_14, bmats.B_2_14, bmats.B_30_4, bmats.B_3_14, bmats.B_4_14, bmats.B_4_17, bmats.B_4_18, bmats.B_4_19, bmats.B_4_20, bmats.B_4_21, bmats.B_4_22, bmats.B_4_23, bmats.B_4_24, bmats.B_4_25, bmats.B_4_26, bmats.B_4_27, bmats.B_4_28, bmats.B_4_29, bmats.B_4_30, bmats.B_4_31, bmats.B_4_32, bmats.B_5_14, bmats.B_6_14, bmats.B_7_14, bmats.B_8_14, bmats.B_9_14, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_14.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
