#include "stdafx.h"
#include "fm_1111.h"

inline int fm_1111(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1935, bmats.Axx2144, bmats.Axx378, bmats.Axx696, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_24, bmats.B_19_10, bmats.Bx5355, bmats.Bx6273, bmats.Bx9809, bmats.Bx9810, bmats.Bx9811, bmats.Bx9812, bmats.Bx9813, bmats.Bx9814, bmats.Bx9815, bmats.Bx9816, bmats.Bx9817, bmats.Bx9818, bmats.Bx9819, bmats.Bx9820, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
