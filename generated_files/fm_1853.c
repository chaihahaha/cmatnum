#include "stdafx.h"
#include "fm_1853.h"

inline int fm_1853(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1810, bmats.Axx2053, bmats.Axx617, bmats.Axx635, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_10_10, bmats.B_10_2, bmats.B_10_6, bmats.B_10_8, bmats.B_9_2, bmats.Bx11091, bmats.Bx12681, bmats.Bx12780, bmats.Bx12781, bmats.Bx2997, bmats.Bx8298, };
    double B_coeffs[11] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
