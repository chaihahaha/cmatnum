#include "stdafx.h"
#include "fm_1422.h"

inline int fm_1422(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1684, bmats.Axx2089, bmats.Axx2213, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.Bx10973, bmats.Bx11267, bmats.Bx11583, bmats.Bx11600, bmats.Bx11601, bmats.Bx11602, bmats.Bx11603, bmats.Bx11604, bmats.Bx11605, bmats.Bx11606, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
