#include "fm_336.h"
#include "stdafx.h"

inline int fm_336(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_30_21, bmats.A_30_22, bmats.A_5_30, bmats.Ax1635, bmats.Ax1653, bmats.Ax529, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_14_21, bmats.B_17_30, bmats.B_18_30, bmats.B_19_30, bmats.B_20_30, bmats.B_21_1, bmats.B_21_10, bmats.B_21_11, bmats.B_21_12, bmats.B_21_13, bmats.B_21_14, bmats.B_21_15, bmats.B_21_16, bmats.B_21_2, bmats.B_21_3, bmats.B_21_30, bmats.B_21_4, bmats.B_21_5, bmats.B_21_6, bmats.B_21_7, bmats.B_21_8, bmats.B_21_9, bmats.B_22_30, bmats.B_23_30, bmats.B_24_30, bmats.B_25_30, bmats.B_26_30, bmats.B_27_30, bmats.B_28_30, bmats.B_29_30, bmats.B_30_30, bmats.B_31_30, bmats.B_32_30, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
