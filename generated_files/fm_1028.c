#include "fm_1028.h"
#include "stdafx.h"

inline int fm_1028(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_1_15, bmats.A_1_16, bmats.A_9_17, bmats.A_9_18, bmats.A_9_19, bmats.A_9_20, bmats.A_9_21, bmats.A_9_22, bmats.A_9_23, bmats.A_9_24, bmats.A_9_25, bmats.A_9_26, bmats.A_9_27, bmats.A_9_28, bmats.A_9_29, bmats.A_9_30, bmats.A_9_31, bmats.A_9_32, bmats.Ax3157, bmats.Ax652, };
    double A_coeffs[20] = {-1, -1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_25, bmats.B_11_25, bmats.B_12_25, bmats.B_13_25, bmats.B_14_25, bmats.B_15_25, bmats.B_16_25, bmats.B_17_1, bmats.B_17_10, bmats.B_17_11, bmats.B_17_12, bmats.B_17_13, bmats.B_17_14, bmats.B_17_15, bmats.B_17_16, bmats.B_17_2, bmats.B_17_3, bmats.B_17_4, bmats.B_17_5, bmats.B_17_6, bmats.B_17_7, bmats.B_17_8, bmats.B_17_9, bmats.B_1_25, bmats.B_2_25, bmats.B_3_25, bmats.B_4_25, bmats.B_5_25, bmats.B_6_25, bmats.B_7_25, bmats.B_8_25, bmats.B_9_1, bmats.B_9_25, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_25.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
