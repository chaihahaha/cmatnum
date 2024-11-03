#include "fm_1204.h"
#include "stdafx.h"

inline int fm_1204(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_3_7, bmats.A_3_8, bmats.A_7_15, bmats.A_7_16, bmats.Ax3461, bmats.Ax3660, bmats.Ax3774, };
    double A_coeffs[7] = {-16, 1, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_10_7, bmats.B_11_7, bmats.B_12_7, bmats.B_13_7, bmats.B_14_7, bmats.B_15_7, bmats.B_16_7, bmats.B_1_7, bmats.B_2_7, bmats.B_3_7, bmats.B_4_7, bmats.B_5_7, bmats.B_6_7, bmats.B_7_1, bmats.B_7_10, bmats.B_7_11, bmats.B_7_12, bmats.B_7_13, bmats.B_7_14, bmats.B_7_15, bmats.B_7_16, bmats.B_7_2, bmats.B_7_3, bmats.B_7_4, bmats.B_7_5, bmats.B_7_6, bmats.B_7_7, bmats.B_7_8, bmats.B_7_9, bmats.B_8_7, bmats.B_9_7, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_7.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
