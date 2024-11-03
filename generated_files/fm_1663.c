#include "fm_1663.h"
#include "stdafx.h"

inline int fm_1663(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_18_31, bmats.A_18_32, bmats.A_20_1, bmats.A_20_10, bmats.A_20_11, bmats.A_20_12, bmats.A_20_13, bmats.A_20_14, bmats.A_20_15, bmats.A_20_16, bmats.A_20_2, bmats.A_20_3, bmats.A_20_4, bmats.A_20_5, bmats.A_20_6, bmats.A_20_7, bmats.A_20_8, bmats.A_20_9, bmats.Ax4329, bmats.Ax600, };
    double A_coeffs[20] = {-1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -16, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_17_4, bmats.B_18_4, bmats.B_19_4, bmats.B_20_18, bmats.B_20_4, bmats.B_2_17, bmats.B_2_18, bmats.B_2_19, bmats.B_2_20, bmats.B_2_21, bmats.B_2_22, bmats.B_2_23, bmats.B_2_24, bmats.B_2_25, bmats.B_2_26, bmats.B_2_27, bmats.B_2_28, bmats.B_2_29, bmats.B_2_30, bmats.B_2_31, bmats.B_2_32, bmats.B_31_4, bmats.B_32_4, bmats.Bx11923, };
    double B_coeffs[24] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_4.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
