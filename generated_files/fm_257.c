#include "fm_257.h"
#include "stdafx.h"

inline int fm_257(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_29_31, bmats.A_29_32, bmats.A_30_13, bmats.A_30_16, bmats.Ax551, bmats.Ax615, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_13_17, bmats.B_13_18, bmats.B_13_19, bmats.B_13_20, bmats.B_13_21, bmats.B_13_22, bmats.B_13_23, bmats.B_13_24, bmats.B_13_25, bmats.B_13_26, bmats.B_13_27, bmats.B_13_28, bmats.B_13_29, bmats.B_13_30, bmats.B_13_31, bmats.B_13_32, bmats.B_17_14, bmats.B_18_14, bmats.B_19_14, bmats.B_20_14, bmats.B_21_14, bmats.B_22_14, bmats.B_23_14, bmats.B_24_14, bmats.B_25_14, bmats.B_26_14, bmats.B_27_14, bmats.B_28_14, bmats.B_29_14, bmats.B_30_14, bmats.B_30_29, bmats.B_31_14, bmats.B_32_14, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_14.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
