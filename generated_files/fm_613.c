#include "fm_613.h"
#include "stdafx.h"

inline int fm_613(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_11, bmats.A_12_12, bmats.A_28_5, bmats.A_28_6, bmats.A_2_11, bmats.A_2_12, bmats.A_5_31, bmats.A_5_32, bmats.Ax2175, bmats.Ax2178, bmats.Ax2216, bmats.Ax2439, bmats.Ax781, };
    double A_coeffs[13] = {-1, 16, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_12_21, bmats.B_17_12, bmats.B_18_12, bmats.B_19_12, bmats.B_20_12, bmats.B_21_12, bmats.B_22_12, bmats.B_23_12, bmats.B_24_12, bmats.B_25_12, bmats.B_26_12, bmats.B_27_12, bmats.B_28_12, bmats.B_29_12, bmats.B_30_12, bmats.B_31_12, bmats.B_32_12, bmats.B_5_1, bmats.B_5_10, bmats.B_5_11, bmats.B_5_12, bmats.B_5_13, bmats.B_5_14, bmats.B_5_15, bmats.B_5_16, bmats.B_5_2, bmats.B_5_3, bmats.B_5_4, bmats.B_5_5, bmats.B_5_6, bmats.B_5_7, bmats.B_5_8, bmats.B_5_9, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_12.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
