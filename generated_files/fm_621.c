#include "stdafx.h"
#include "fm_621.h"

inline int fm_621(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2551, bmats.Axx279, bmats.Axx36, bmats.Axx934, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_32_27, bmats.Bx5636, bmats.Bx5637, bmats.Bx5638, bmats.Bx5639, bmats.Bx5640, bmats.Bx5641, bmats.Bx5642, bmats.Bx5643, bmats.Bx5644, bmats.Bx5645, bmats.Bx5646, bmats.Bx5647, bmats.Bx5648, bmats.Bx5650, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
