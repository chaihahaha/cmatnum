#include "fm_14861.h"
#include "stdafx.h"

inline int fm_14861(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_31_1, bmats.A_31_10, bmats.A_31_11, bmats.A_31_12, bmats.A_31_13, bmats.A_31_14, bmats.A_31_15, bmats.A_31_16, bmats.A_31_2, bmats.A_31_3, bmats.A_31_4, bmats.A_31_5, bmats.A_31_6, bmats.A_31_7, bmats.A_31_8, bmats.A_31_9, bmats.A_32_31, bmats.A_32_32, bmats.Ax533, bmats.Ax791, };
    double A_coeffs[20] = {1, 1, 1, 1, 1, 1, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_16_17, bmats.B_16_18, bmats.B_16_19, bmats.B_16_20, bmats.B_16_21, bmats.B_16_22, bmats.B_16_23, bmats.B_16_24, bmats.B_16_25, bmats.B_16_26, bmats.B_16_27, bmats.B_16_28, bmats.B_16_29, bmats.B_16_30, bmats.B_16_31, bmats.B_16_32, bmats.B_31_32, bmats.Bx13385, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_15.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
