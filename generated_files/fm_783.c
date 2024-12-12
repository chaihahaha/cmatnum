#include "stdafx.h"
#include "fm_783.h"

inline int fm_783(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2006, bmats.Axx2586, bmats.Axx2596, bmats.Axx78, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.Bx6061, bmats.Bx7188, bmats.Bx7232, bmats.Bx7253, bmats.Bx7294, bmats.Bx7295, bmats.Bx7296, bmats.Bx7297, bmats.Bx7298, bmats.Bx7299, bmats.Bx7300, bmats.Bx7301, bmats.Bx7302, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
