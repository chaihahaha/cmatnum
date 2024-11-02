#include "fm_384.h"

inline int fm_384(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_13_31, bmats.A_13_32, bmats.A_18_29, bmats.A_18_30, bmats.A_29_29, bmats.A_29_30, bmats.A_31_15, bmats.A_31_16, bmats.Ax1091, bmats.Ax1106, bmats.Ax1834, bmats.Ax679, bmats.Ax760, };
    double A_coeffs[13] = {16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_29, bmats.B_11_29, bmats.B_12_29, bmats.B_13_29, bmats.B_14_29, bmats.B_15_29, bmats.B_16_29, bmats.B_1_29, bmats.B_29_15, bmats.B_2_29, bmats.B_31_17, bmats.B_31_18, bmats.B_31_19, bmats.B_31_20, bmats.B_31_21, bmats.B_31_22, bmats.B_31_23, bmats.B_31_24, bmats.B_31_25, bmats.B_31_26, bmats.B_31_27, bmats.B_31_28, bmats.B_31_29, bmats.B_31_30, bmats.B_31_31, bmats.B_31_32, bmats.B_3_29, bmats.B_4_29, bmats.B_5_29, bmats.B_6_29, bmats.B_7_29, bmats.B_8_29, bmats.B_9_29, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_29.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
