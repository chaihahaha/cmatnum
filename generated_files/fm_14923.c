#include "fm_14923.h"
#include "stdafx.h"

inline int fm_14923(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_16_7, bmats.A_16_8, bmats.A_24_15, bmats.Ax1469, bmats.Ax3489, bmats.Ax7798, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_10_16, bmats.B_12_16, bmats.B_1_16, bmats.B_32_8, bmats.B_8_16, bmats.B_9_16, bmats.Bx10449, bmats.Bx13230, };
    double B_coeffs[8] = {-1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_16.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
