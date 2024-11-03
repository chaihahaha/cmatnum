#include "fm_1142.h"
#include "stdafx.h"

inline int fm_1142(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_1_30, bmats.A_24_17, bmats.A_24_18, bmats.Ax100, bmats.Ax3419, bmats.Ax739, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_1, bmats.B_17_10, bmats.B_17_11, bmats.B_17_12, bmats.B_17_13, bmats.B_17_14, bmats.B_17_15, bmats.B_17_16, bmats.B_17_2, bmats.B_17_24, bmats.B_17_3, bmats.B_17_4, bmats.B_17_5, bmats.B_17_6, bmats.B_17_7, bmats.B_17_8, bmats.B_17_9, bmats.B_18_24, bmats.B_19_24, bmats.B_20_24, bmats.B_21_24, bmats.B_22_24, bmats.B_23_24, bmats.B_24_24, bmats.B_25_24, bmats.B_26_24, bmats.B_27_24, bmats.B_28_24, bmats.B_29_24, bmats.B_30_24, bmats.B_31_24, bmats.B_32_24, bmats.B_8_17, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_24.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
