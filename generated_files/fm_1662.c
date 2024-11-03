#include "fm_1662.h"
#include "stdafx.h"

inline int fm_1662(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_2_15, bmats.A_2_16, bmats.A_4_17, bmats.A_4_18, bmats.A_4_19, bmats.A_4_20, bmats.A_4_21, bmats.A_4_22, bmats.A_4_23, bmats.A_4_24, bmats.A_4_25, bmats.A_4_26, bmats.A_4_27, bmats.A_4_28, bmats.A_4_29, bmats.A_4_30, bmats.A_4_31, bmats.A_4_32, bmats.Ax4311, bmats.Ax556, };
    double A_coeffs[20] = {-1, -1, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_13_20, bmats.B_15_20, bmats.B_16_20, bmats.B_18_1, bmats.B_18_10, bmats.B_18_11, bmats.B_18_12, bmats.B_18_13, bmats.B_18_14, bmats.B_18_15, bmats.B_18_16, bmats.B_18_2, bmats.B_18_3, bmats.B_18_4, bmats.B_18_5, bmats.B_18_6, bmats.B_18_7, bmats.B_18_8, bmats.B_18_9, bmats.B_1_20, bmats.B_2_20, bmats.B_3_20, bmats.B_4_2, bmats.B_4_20, bmats.B_6_20, bmats.Bx12111, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
