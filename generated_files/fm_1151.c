#include "stdafx.h"
#include "fm_1151.h"

inline int fm_1151(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1797, bmats.Axx2025, bmats.Axx2545, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.Bx10171, bmats.Bx10191, bmats.Bx10192, bmats.Bx10193, bmats.Bx10194, bmats.Bx10195, bmats.Bx10196, bmats.Bx10197, bmats.Bx10198, bmats.Bx10199, bmats.Bx10200, bmats.Bx9318, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
