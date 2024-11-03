#include "fm_1623.h"
#include "stdafx.h"

inline int fm_1623(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_3_3, bmats.A_3_4, bmats.A_4_15, bmats.A_4_16, bmats.Ax4339, bmats.Ax4368, bmats.Ax4447, };
    double A_coeffs[7] = {1, -16, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_10_4, bmats.B_11_4, bmats.B_12_4, bmats.B_13_4, bmats.B_14_4, bmats.B_15_4, bmats.B_16_4, bmats.B_1_4, bmats.B_2_4, bmats.B_3_4, bmats.B_4_1, bmats.B_4_10, bmats.B_4_11, bmats.B_4_12, bmats.B_4_13, bmats.B_4_14, bmats.B_4_15, bmats.B_4_16, bmats.B_4_2, bmats.B_4_3, bmats.B_4_4, bmats.B_4_5, bmats.B_4_6, bmats.B_4_7, bmats.B_4_8, bmats.B_4_9, bmats.B_5_4, bmats.B_6_4, bmats.B_7_4, bmats.B_8_4, bmats.B_9_4, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_4.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
