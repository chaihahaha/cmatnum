#include "stdafx.h"
#include "fm_636.h"

inline int fm_636(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2162, bmats.Axx2683, bmats.Axx830, bmats.Axx838, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_11_12, bmats.B_12_12, bmats.B_13_12, bmats.B_16_12, bmats.B_2_12, bmats.B_2_13, bmats.B_2_2, bmats.Bx5841, bmats.Bx5842, bmats.Bx5843, bmats.Bx5844, bmats.Bx5845, bmats.Bx5846, bmats.Bx5847, bmats.Bx5848, bmats.Bx5849, bmats.Bx5850, bmats.Bx5851, bmats.Bx5852, bmats.Bx694, };
    double B_coeffs[20] = {-1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
