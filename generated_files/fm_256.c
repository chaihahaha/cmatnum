#include "fm_256.h"
#include "stdafx.h"

inline int fm_256(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_15, bmats.A_13_16, bmats.A_14_29, bmats.A_14_32, bmats.Ax530, bmats.Ax568, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_30, bmats.B_11_30, bmats.B_12_30, bmats.B_13_30, bmats.B_14_13, bmats.B_14_30, bmats.B_15_30, bmats.B_16_30, bmats.B_1_30, bmats.B_29_1, bmats.B_29_10, bmats.B_29_11, bmats.B_29_12, bmats.B_29_13, bmats.B_29_14, bmats.B_29_15, bmats.B_29_16, bmats.B_29_2, bmats.B_29_3, bmats.B_29_4, bmats.B_29_5, bmats.B_29_6, bmats.B_29_7, bmats.B_29_8, bmats.B_29_9, bmats.B_2_30, bmats.B_3_30, bmats.B_4_30, bmats.B_5_30, bmats.B_6_30, bmats.B_7_30, bmats.B_8_30, bmats.B_9_30, };
    double B_coeffs[33] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
