#include "fm_1101.h"

inline int fm_1101(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_24_15, bmats.A_8_7, bmats.A_8_8, bmats.Ax1469, bmats.Ax3450, bmats.Ax3486, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_8, bmats.B_11_8, bmats.B_12_8, bmats.B_13_8, bmats.B_14_8, bmats.B_15_8, bmats.B_16_8, bmats.B_1_8, bmats.B_24_8, bmats.B_2_8, bmats.B_3_8, bmats.B_4_8, bmats.B_5_8, bmats.B_6_8, bmats.B_7_8, bmats.B_8_17, bmats.B_8_18, bmats.B_8_19, bmats.B_8_20, bmats.B_8_21, bmats.B_8_22, bmats.B_8_23, bmats.B_8_24, bmats.B_8_25, bmats.B_8_26, bmats.B_8_27, bmats.B_8_28, bmats.B_8_29, bmats.B_8_30, bmats.B_8_31, bmats.B_8_32, bmats.B_8_8, bmats.B_9_8, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_8.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
