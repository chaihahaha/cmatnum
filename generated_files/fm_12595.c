#include "stdafx.h"
#include "fm_12595.h"

int fm_12595(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_12_31, bmats.A_12_32, bmats.A_29_17, bmats.A_29_18, bmats.A_29_19, bmats.A_29_20, bmats.A_29_28, bmats.A_29_29, bmats.A_29_30, bmats.A_31_13, bmats.A_31_14, bmats.Ax482, bmats.Ax7538, bmats.Ax757, };
    double A_coeffs[14] = {16, -1, 1, 1, 1, 1, -16, 1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_13_28, bmats.B_28_15, bmats.B_31_29, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_29_15.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
