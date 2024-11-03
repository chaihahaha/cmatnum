#include "fm_782.h"
#include "stdafx.h"

inline int fm_782(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_26, bmats.A_10_31, bmats.A_15_15, bmats.A_15_16, bmats.Ax2970, bmats.Ax649, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_15, bmats.B_10_26, bmats.B_11_26, bmats.B_12_26, bmats.B_13_26, bmats.B_14_26, bmats.B_15_26, bmats.B_16_26, bmats.B_1_26, bmats.B_2_26, bmats.B_31_1, bmats.B_31_10, bmats.B_31_11, bmats.B_31_12, bmats.B_31_13, bmats.B_31_14, bmats.B_31_15, bmats.B_31_16, bmats.B_31_2, bmats.B_31_3, bmats.B_31_4, bmats.B_31_5, bmats.B_31_6, bmats.B_31_7, bmats.B_31_8, bmats.B_31_9, bmats.B_3_26, bmats.B_4_26, bmats.B_5_26, bmats.B_6_26, bmats.B_7_26, bmats.B_8_26, bmats.B_9_26, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_26.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
