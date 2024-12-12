#include "stdafx.h"
#include "fm_642.h"

inline int fm_642(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1011, bmats.Axx1016, bmats.Axx1656, bmats.Axx1677, bmats.Axx1696, bmats.Axx1729, bmats.Axx209, bmats.Axx211, bmats.Axx2167, bmats.Axx2412, bmats.Axx248, bmats.Axx2858, bmats.Axx2929, bmats.Axx3365, bmats.Axx372, bmats.Axx380, bmats.Axx644, bmats.Axx888, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4812, bmats.Bx5841, bmats.Bx5905, bmats.Bx5920, bmats.Bx5921, bmats.Bx5922, bmats.Bx5923, bmats.Bx5924, bmats.Bx5925, bmats.Bx5926, bmats.Bx5927, bmats.Bx5928, bmats.Bx5929, bmats.Bx5930, bmats.Bx5931, bmats.Bx5932, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
