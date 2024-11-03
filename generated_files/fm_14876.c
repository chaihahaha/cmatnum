#include "fm_14876.h"
#include "stdafx.h"

inline int fm_14876(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_16_17, bmats.A_16_18, bmats.A_2_15, bmats.A_2_16, bmats.Ax556, bmats.Ax8496, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_32, bmats.B_11_32, bmats.B_12_32, bmats.B_13_32, bmats.B_14_32, bmats.B_15_32, bmats.B_16_2, bmats.B_16_32, bmats.B_18_1, bmats.B_18_10, bmats.B_18_11, bmats.B_18_12, bmats.B_18_13, bmats.B_18_14, bmats.B_18_15, bmats.B_18_16, bmats.B_18_2, bmats.B_18_3, bmats.B_18_4, bmats.B_18_5, bmats.B_18_6, bmats.B_18_7, bmats.B_18_8, bmats.B_18_9, bmats.B_1_32, bmats.B_2_32, bmats.B_3_32, bmats.B_4_32, bmats.B_5_32, bmats.B_6_32, bmats.B_7_32, bmats.B_8_32, bmats.B_9_32, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
