#include "fm_1539.h"
#include "stdafx.h"

inline int fm_1539(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_17_31, bmats.A_17_32, bmats.A_21_1, bmats.A_21_10, bmats.A_21_11, bmats.A_21_12, bmats.A_21_13, bmats.A_21_14, bmats.A_21_15, bmats.A_21_16, bmats.A_21_2, bmats.A_21_3, bmats.A_21_4, bmats.A_21_5, bmats.A_21_6, bmats.A_21_7, bmats.A_21_8, bmats.A_21_9, bmats.Ax4126, bmats.Ax667, };
    double A_coeffs[20] = {-1, -1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_17_5, bmats.B_18_5, bmats.B_19_5, bmats.B_1_17, bmats.B_1_18, bmats.B_1_19, bmats.B_1_20, bmats.B_1_21, bmats.B_1_22, bmats.B_1_23, bmats.B_1_24, bmats.B_1_25, bmats.B_1_26, bmats.B_1_27, bmats.B_1_28, bmats.B_1_29, bmats.B_1_30, bmats.B_1_31, bmats.B_1_32, bmats.B_20_5, bmats.B_21_17, bmats.B_21_5, bmats.B_28_5, bmats.B_30_5, bmats.B_31_5, bmats.B_32_5, bmats.Bx11450, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_5.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
