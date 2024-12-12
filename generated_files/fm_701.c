#include "stdafx.h"
#include "fm_701.h"

inline int fm_701(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2780, bmats.Axx3107, bmats.Axx3109, bmats.Axx779, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx6311, bmats.Bx6323, bmats.Bx6380, bmats.Bx6394, bmats.Bx6395, bmats.Bx6396, bmats.Bx6397, bmats.Bx6398, bmats.Bx6399, bmats.Bx6400, bmats.Bx6401, bmats.Bx6402, bmats.Bx6403, bmats.Bx6404, bmats.Bx6405, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
