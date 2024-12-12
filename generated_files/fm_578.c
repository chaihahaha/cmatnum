#include "stdafx.h"
#include "fm_578.h"

inline int fm_578(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1779, bmats.Axx1810, bmats.Axx752, bmats.Axx780, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_4_12, bmats.B_7_12, bmats.Bx3719, bmats.Bx5075, bmats.Bx5076, bmats.Bx5077, bmats.Bx5078, bmats.Bx5079, bmats.Bx5080, bmats.Bx5081, bmats.Bx5082, bmats.Bx5083, bmats.Bx5084, bmats.Bx5085, bmats.Bx5086, bmats.Bx5087, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
