#include "fm_14890.h"
#include "stdafx.h"

inline int fm_14890(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_32_19, bmats.A_32_20, bmats.A_4_31, bmats.Ax1587, bmats.Ax4376, bmats.Ax7799, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_16_20, bmats.B_20_1, bmats.B_20_10, bmats.B_20_11, bmats.B_20_12, bmats.B_20_13, bmats.B_20_14, bmats.B_20_15, bmats.B_20_16, bmats.B_20_2, bmats.B_20_3, bmats.B_20_4, bmats.B_20_5, bmats.B_20_6, bmats.B_20_7, bmats.B_20_8, bmats.B_20_9, bmats.B_21_32, bmats.B_22_32, bmats.B_23_32, bmats.B_24_32, bmats.B_30_32, bmats.B_31_32, bmats.B_32_32, bmats.Bx13349, };
    double B_coeffs[25] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
