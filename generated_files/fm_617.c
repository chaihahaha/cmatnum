#include "stdafx.h"
#include "fm_617.h"

inline int fm_617(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1630, bmats.Axx1677, bmats.Axx1823, bmats.Axx1868, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4812, bmats.Bx5501, bmats.Bx5565, bmats.Bx5580, bmats.Bx5581, bmats.Bx5582, bmats.Bx5583, bmats.Bx5584, bmats.Bx5585, bmats.Bx5586, bmats.Bx5587, bmats.Bx5588, bmats.Bx5589, bmats.Bx5590, bmats.Bx5591, bmats.Bx5592, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
