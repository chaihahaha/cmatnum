#include "stdafx.h"
#include "fm_13337.h"

int fm_13337(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_15, bmats.A_12_16, bmats.A_14_31, bmats.A_14_32, bmats.A_16_15, bmats.A_16_16, bmats.A_32_13, bmats.A_32_14, bmats.Ax463, bmats.Ax485, bmats.Ax565, bmats.Ax745, bmats.Ax7791, };
    double A_coeffs[13] = {-1, 16, -1, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_14_12, bmats.B_16_30, bmats.B_31_16, bmats.B_32_16, bmats.Bx13360, bmats.Bx3105, bmats.Bx3115, };
    double B_coeffs[7] = {-1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
