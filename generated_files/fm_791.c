#include "fm_791.h"
#include "stdafx.h"

inline int fm_791(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_26_10, bmats.A_26_15, bmats.A_26_31, bmats.A_26_32, bmats.Ax2971, bmats.Ax627, };
    double A_coeffs[6] = {-16, 1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_17, bmats.B_10_18, bmats.B_10_19, bmats.B_10_20, bmats.B_10_21, bmats.B_10_22, bmats.B_10_23, bmats.B_10_24, bmats.B_10_25, bmats.B_10_26, bmats.B_10_27, bmats.B_10_28, bmats.B_10_29, bmats.B_10_30, bmats.B_10_31, bmats.B_10_32, bmats.B_17_10, bmats.B_18_10, bmats.B_19_10, bmats.B_20_10, bmats.B_21_10, bmats.B_22_10, bmats.B_23_10, bmats.B_24_10, bmats.B_25_10, bmats.B_26_10, bmats.B_26_26, bmats.B_27_10, bmats.B_28_10, bmats.B_29_10, bmats.B_30_10, bmats.B_31_10, bmats.B_32_10, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_10.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
