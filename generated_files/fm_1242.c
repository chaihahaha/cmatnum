#include "fm_1242.h"

inline int fm_1242(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_5_15, bmats.A_5_16, bmats.A_7_21, bmats.A_7_22, bmats.Ax3830, bmats.Ax591, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 28;
    double_cmat B_mats[28] = {bmats.B_12_23, bmats.B_13_23, bmats.B_15_23, bmats.B_16_23, bmats.B_1_23, bmats.B_21_1, bmats.B_21_10, bmats.B_21_11, bmats.B_21_12, bmats.B_21_13, bmats.B_21_14, bmats.B_21_15, bmats.B_21_16, bmats.B_21_2, bmats.B_21_3, bmats.B_21_4, bmats.B_21_5, bmats.B_21_6, bmats.B_21_7, bmats.B_21_8, bmats.B_21_9, bmats.B_2_23, bmats.B_3_23, bmats.B_4_23, bmats.B_5_23, bmats.B_6_23, bmats.B_7_5, bmats.Bx10243, };
    double B_coeffs[28] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_23.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
