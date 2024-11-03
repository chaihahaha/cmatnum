#include "fm_14842.h"
#include "stdafx.h"

inline int fm_14842(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 5;
    double_cmat A_mats[5] = {bmats.A_31_29, bmats.A_31_30, bmats.Ax1079, bmats.Ax1868, bmats.Ax722, };
    double A_coeffs[5] = {1, -16, 1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_15_30, bmats.B_18_31, bmats.B_19_31, bmats.B_20_31, bmats.B_21_31, bmats.B_22_31, bmats.B_23_31, bmats.B_24_31, bmats.B_30_1, bmats.B_30_31, bmats.B_31_31, bmats.Bx13390, bmats.Bx2491, };
    double B_coeffs[13] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
