#include "stdafx.h"
#include "fm_619.h"

inline int fm_619(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1587, bmats.Axx392, bmats.Axx432, bmats.Axx718, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_6_12, bmats.Bx3603, bmats.Bx4354, bmats.Bx5048, bmats.Bx5606, bmats.Bx5607, bmats.Bx5608, bmats.Bx5609, bmats.Bx5610, bmats.Bx5611, bmats.Bx5612, bmats.Bx5613, bmats.Bx5614, bmats.Bx5615, bmats.Bx5616, bmats.Bx5617, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
