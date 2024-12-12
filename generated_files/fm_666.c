#include "stdafx.h"
#include "fm_666.h"

inline int fm_666(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1622, bmats.Axx1776, bmats.Axx2166, bmats.Axx418, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_1_27, bmats.B_2_27, bmats.B_3_27, bmats.Bx4224, bmats.Bx5995, bmats.Bx6040, bmats.Bx6062, bmats.Bx6063, bmats.Bx6064, bmats.Bx6065, bmats.Bx6066, bmats.Bx6067, bmats.Bx6068, bmats.Bx6069, bmats.Bx6070, bmats.Bx6071, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
