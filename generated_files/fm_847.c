#include "fm_847.h"

inline int fm_847(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_5, bmats.A_10_6, bmats.A_21_14, bmats.Ax1674, bmats.Ax2874, bmats.Ax3074, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_10, bmats.B_11_10, bmats.B_12_10, bmats.B_13_10, bmats.B_14_10, bmats.B_15_10, bmats.B_16_10, bmats.B_1_10, bmats.B_26_5, bmats.B_2_10, bmats.B_3_10, bmats.B_4_10, bmats.B_5_10, bmats.B_5_17, bmats.B_5_18, bmats.B_5_19, bmats.B_5_20, bmats.B_5_21, bmats.B_5_22, bmats.B_5_23, bmats.B_5_24, bmats.B_5_25, bmats.B_5_26, bmats.B_5_27, bmats.B_5_28, bmats.B_5_29, bmats.B_5_30, bmats.B_5_31, bmats.B_5_32, bmats.B_6_10, bmats.B_7_10, bmats.B_8_10, bmats.B_9_10, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_10.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
