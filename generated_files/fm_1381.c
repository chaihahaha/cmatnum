#include "fm_1381.h"
#include "stdafx.h"

inline int fm_1381(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_18_14, bmats.A_6_1, bmats.A_6_2, bmats.Ax3867, bmats.Ax4087, bmats.Ax898, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_14_6, bmats.B_15_6, bmats.B_16_6, bmats.B_1_6, bmats.B_22_2, bmats.B_2_17, bmats.B_2_18, bmats.B_2_19, bmats.B_2_20, bmats.B_2_21, bmats.B_2_22, bmats.B_2_23, bmats.B_2_24, bmats.B_2_25, bmats.B_2_26, bmats.B_2_27, bmats.B_2_28, bmats.B_2_29, bmats.B_2_30, bmats.B_2_31, bmats.B_2_32, bmats.B_2_6, bmats.B_3_6, bmats.B_4_6, bmats.B_5_6, bmats.Bx10888, };
    double B_coeffs[26] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_6.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
