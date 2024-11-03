#include "fm_1096.h"
#include "stdafx.h"

inline int fm_1096(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_3_7, bmats.A_3_8, bmats.A_8_15, bmats.A_8_16, bmats.Ax3461, bmats.Ax3491, bmats.Ax3569, };
    double A_coeffs[7] = {1, -16, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_10_8, bmats.B_11_8, bmats.B_12_8, bmats.B_13_8, bmats.B_14_8, bmats.B_15_8, bmats.B_16_8, bmats.B_1_8, bmats.B_2_8, bmats.B_3_8, bmats.B_4_8, bmats.B_5_8, bmats.B_6_8, bmats.B_7_8, bmats.B_8_1, bmats.B_8_10, bmats.B_8_11, bmats.B_8_12, bmats.B_8_13, bmats.B_8_14, bmats.B_8_15, bmats.B_8_16, bmats.B_8_2, bmats.B_8_3, bmats.B_8_4, bmats.B_8_5, bmats.B_8_6, bmats.B_8_7, bmats.B_8_8, bmats.B_8_9, bmats.B_9_8, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_8.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
