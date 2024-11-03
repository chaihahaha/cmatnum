#include "fm_709.h"
#include "stdafx.h"

inline int fm_709(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_24_31, bmats.A_24_32, bmats.A_27_7, bmats.A_27_8, bmats.Ax2735, bmats.Ax621, };
    double A_coeffs[6] = {-1, -1, 1, -16, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_11, bmats.B_18_11, bmats.B_19_11, bmats.B_20_11, bmats.B_21_11, bmats.B_22_11, bmats.B_23_11, bmats.B_24_11, bmats.B_25_11, bmats.B_26_11, bmats.B_27_11, bmats.B_27_24, bmats.B_28_11, bmats.B_29_11, bmats.B_30_11, bmats.B_31_11, bmats.B_32_11, bmats.B_8_17, bmats.B_8_18, bmats.B_8_19, bmats.B_8_20, bmats.B_8_21, bmats.B_8_22, bmats.B_8_23, bmats.B_8_24, bmats.B_8_25, bmats.B_8_26, bmats.B_8_27, bmats.B_8_28, bmats.B_8_29, bmats.B_8_30, bmats.B_8_31, bmats.B_8_32, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_11.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
