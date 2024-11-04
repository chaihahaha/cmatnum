#include "stdafx.h"
#include "fm_1164.h"

int fm_1164(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_31, bmats.A_14_32, bmats.A_23_13, bmats.A_23_14, bmats.A_3_7, bmats.A_3_8, bmats.A_7_7, bmats.A_7_8, bmats.Ax3458, bmats.Ax3461, bmats.Ax3660, bmats.Ax500, bmats.Ax745, };
    double A_coeffs[13] = {-1, -1, -1, 16, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_14_12, bmats.B_7_30, bmats.Bx10240, bmats.Bx3105, bmats.Bx3115, };
    double B_coeffs[5] = {-1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
