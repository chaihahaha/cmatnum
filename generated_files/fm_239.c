#include "fm_239.h"
#include "stdafx.h"

inline int fm_239(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_15_17, bmats.A_15_18, bmats.A_1_15, bmats.A_1_16, bmats.Ax652, bmats.Ax827, };
    double A_coeffs[6] = {-16, 1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_31, bmats.B_11_31, bmats.B_12_31, bmats.B_13_31, bmats.B_14_31, bmats.B_15_1, bmats.B_15_31, bmats.B_16_31, bmats.B_17_1, bmats.B_17_10, bmats.B_17_11, bmats.B_17_12, bmats.B_17_13, bmats.B_17_14, bmats.B_17_15, bmats.B_17_16, bmats.B_17_2, bmats.B_17_3, bmats.B_17_4, bmats.B_17_5, bmats.B_17_6, bmats.B_17_7, bmats.B_17_8, bmats.B_17_9, bmats.B_1_31, bmats.B_2_31, bmats.B_3_31, bmats.B_4_31, bmats.B_5_31, bmats.B_6_31, bmats.B_7_31, bmats.B_8_31, bmats.B_9_31, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
