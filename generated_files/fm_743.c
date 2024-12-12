#include "stdafx.h"
#include "fm_743.h"

inline int fm_743(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx141, bmats.Axx167, bmats.Axx1780, bmats.Axx2081, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_1_11, bmats.B_1_13, bmats.Bx6512, bmats.Bx6897, bmats.Bx6898, bmats.Bx6899, bmats.Bx6900, bmats.Bx6901, bmats.Bx6902, bmats.Bx6903, bmats.Bx6904, bmats.Bx6905, bmats.Bx6906, bmats.Bx6907, bmats.Bx6908, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
