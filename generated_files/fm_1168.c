#include "fm_1168.h"
#include "stdafx.h"

inline int fm_1168(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_15, bmats.A_14_16, bmats.A_7_29, bmats.A_7_30, bmats.Ax3740, bmats.Ax392, };
    double A_coeffs[6] = {-1, -1, 1, -16, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_12_23, bmats.B_13_23, bmats.B_15_23, bmats.B_16_23, bmats.B_1_23, bmats.B_2_23, bmats.B_30_1, bmats.B_3_23, bmats.B_4_23, bmats.B_5_23, bmats.B_6_23, bmats.B_7_14, bmats.Bx10243, bmats.Bx2491, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_23.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
