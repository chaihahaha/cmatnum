#include "fm_713.h"
#include "stdafx.h"

inline int fm_713(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_11_25, bmats.A_11_26, bmats.A_19_27, bmats.A_19_28, bmats.A_25_15, bmats.A_25_16, bmats.A_27_27, bmats.A_27_28, bmats.Ax2230, bmats.Ax2567, bmats.Ax2674, bmats.Ax28, bmats.Ax700, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_27, bmats.B_11_27, bmats.B_12_27, bmats.B_13_27, bmats.B_14_27, bmats.B_15_27, bmats.B_16_27, bmats.B_1_27, bmats.B_25_17, bmats.B_25_18, bmats.B_25_19, bmats.B_25_20, bmats.B_25_21, bmats.B_25_22, bmats.B_25_23, bmats.B_25_24, bmats.B_25_25, bmats.B_25_26, bmats.B_25_27, bmats.B_25_28, bmats.B_25_29, bmats.B_25_30, bmats.B_25_31, bmats.B_25_32, bmats.B_27_9, bmats.B_2_27, bmats.B_3_27, bmats.B_4_27, bmats.B_5_27, bmats.B_6_27, bmats.B_7_27, bmats.B_8_27, bmats.B_9_27, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
