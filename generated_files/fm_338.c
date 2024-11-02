#include "fm_338.h"

inline int fm_338(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_20, bmats.A_14_21, bmats.A_5_15, bmats.A_5_16, bmats.Ax1613, bmats.Ax591, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_30, bmats.B_11_30, bmats.B_12_30, bmats.B_13_30, bmats.B_14_30, bmats.B_14_5, bmats.B_15_30, bmats.B_16_30, bmats.B_1_30, bmats.B_21_1, bmats.B_21_10, bmats.B_21_11, bmats.B_21_12, bmats.B_21_13, bmats.B_21_14, bmats.B_21_15, bmats.B_21_16, bmats.B_21_2, bmats.B_21_3, bmats.B_21_4, bmats.B_21_5, bmats.B_21_6, bmats.B_21_7, bmats.B_21_8, bmats.B_21_9, bmats.B_2_30, bmats.B_3_30, bmats.B_4_30, bmats.B_5_30, bmats.B_6_30, bmats.B_7_30, bmats.B_8_30, bmats.B_9_30, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
