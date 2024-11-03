#include "fm_14924.h"
#include "stdafx.h"

inline int fm_14924(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_16_23, bmats.A_16_24, bmats.A_8_15, bmats.A_8_16, bmats.Ax576, bmats.Ax8508, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_15_32, bmats.B_16_32, bmats.B_16_8, bmats.B_24_1, bmats.B_24_2, bmats.B_24_3, bmats.B_24_4, bmats.B_24_5, bmats.Bx13238, bmats.Bx9722, };
    double B_coeffs[10] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
