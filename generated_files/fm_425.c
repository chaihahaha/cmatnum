#include "fm_425.h"

inline int fm_425(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_13_23, bmats.A_13_24, bmats.A_18_29, bmats.A_18_30, bmats.A_24_15, bmats.A_24_16, bmats.A_29_29, bmats.A_29_30, bmats.Ax1091, bmats.Ax1106, bmats.Ax1834, bmats.Ax2028, bmats.Ax697, };
    double A_coeffs[13] = {-1, 16, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_29, bmats.B_11_29, bmats.B_12_29, bmats.B_13_29, bmats.B_14_29, bmats.B_15_29, bmats.B_16_29, bmats.B_1_29, bmats.B_24_17, bmats.B_24_18, bmats.B_24_19, bmats.B_24_20, bmats.B_24_21, bmats.B_24_22, bmats.B_24_23, bmats.B_24_24, bmats.B_24_25, bmats.B_24_26, bmats.B_24_27, bmats.B_24_28, bmats.B_24_29, bmats.B_24_30, bmats.B_24_31, bmats.B_24_32, bmats.B_29_8, bmats.B_2_29, bmats.B_3_29, bmats.B_4_29, bmats.B_5_29, bmats.B_6_29, bmats.B_7_29, bmats.B_8_29, bmats.B_9_29, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_29.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
