#include "stdafx.h"
#include "fm_1392.h"

inline int fm_1392(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1642, bmats.Axx385, bmats.Axx407, bmats.Axx445, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_4_6, bmats.Bx10889, bmats.Bx11096, bmats.Bx11389, bmats.Bx11390, bmats.Bx11391, bmats.Bx11392, bmats.Bx11393, bmats.Bx11394, bmats.Bx8226, bmats.Bx9486, };
    double B_coeffs[11] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
