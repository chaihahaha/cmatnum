#include "stdafx.h"
#include "fm_586.h"

inline int fm_586(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1810, bmats.Axx695, bmats.Axx711, bmats.Axx738, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_6_12, bmats.B_8_12, bmats.Bx5087, bmats.Bx5178, bmats.Bx5179, bmats.Bx5180, bmats.Bx5181, bmats.Bx5182, bmats.Bx5183, bmats.Bx5184, bmats.Bx5185, bmats.Bx5186, bmats.Bx5187, bmats.Bx5188, bmats.Bx5189, bmats.Bx5190, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
