#include "fm_1882.h"
#include "stdafx.h"

inline int fm_1882(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_18_23, bmats.A_18_24, bmats.A_7_32, bmats.Ax1388, bmats.Ax340, bmats.Ax4678, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_17_18, bmats.B_21_18, bmats.B_22_18, bmats.B_23_10, bmats.B_23_11, bmats.B_23_12, bmats.B_23_13, bmats.B_23_14, bmats.B_23_15, bmats.B_23_16, bmats.B_23_7, bmats.B_23_8, bmats.B_23_9, bmats.B_2_23, bmats.B_30_18, bmats.B_31_18, bmats.B_32_18, bmats.Bx11066, bmats.Bx12662, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_18.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
