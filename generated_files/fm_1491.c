#include "stdafx.h"
#include "fm_1491.h"

inline int fm_1491(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1919, bmats.Axx2107, bmats.Axx457, bmats.Axx487, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_10_5, bmats.B_6_5, bmats.B_7_5, bmats.B_8_5, bmats.B_8_6, bmats.B_9_5, bmats.Bx10432, bmats.Bx11489, bmats.Bx11642, bmats.Bx11646, bmats.Bx11654, bmats.Bx11721, bmats.Bx11722, bmats.Bx3807, bmats.Bx4973, bmats.Bx6416, bmats.Bx8917, };
    double B_coeffs[17] = {-1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
