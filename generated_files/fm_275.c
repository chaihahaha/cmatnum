#include "fm_275.h"
#include "stdafx.h"

inline int fm_275(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_30_32, bmats.A_31_29, bmats.A_31_30, bmats.A_32_30, bmats.Ax1079, bmats.Ax1145, };
    double A_coeffs[6] = {17, 1, -16, -17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_30, bmats.B_18_30, bmats.B_19_30, bmats.B_20_30, bmats.B_21_30, bmats.B_22_30, bmats.B_23_30, bmats.B_24_30, bmats.B_25_30, bmats.B_26_30, bmats.B_27_30, bmats.B_28_30, bmats.B_29_30, bmats.B_30_30, bmats.B_30_32, bmats.B_31_30, bmats.B_32_17, bmats.B_32_18, bmats.B_32_19, bmats.B_32_20, bmats.B_32_21, bmats.B_32_22, bmats.B_32_23, bmats.B_32_24, bmats.B_32_25, bmats.B_32_26, bmats.B_32_27, bmats.B_32_28, bmats.B_32_29, bmats.B_32_30, bmats.B_32_31, bmats.B_32_32, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_30.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
