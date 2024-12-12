#include "stdafx.h"
#include "fm_610.h"

inline int fm_610(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2596, bmats.Axx3021, bmats.Axx3023, bmats.Axx3129, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4694, bmats.Bx5408, bmats.Bx5474, bmats.Bx5488, bmats.Bx5489, bmats.Bx5490, bmats.Bx5491, bmats.Bx5492, bmats.Bx5493, bmats.Bx5494, bmats.Bx5495, bmats.Bx5496, bmats.Bx5497, bmats.Bx5498, bmats.Bx5499, bmats.Bx5500, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
