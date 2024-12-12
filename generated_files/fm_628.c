#include "stdafx.h"
#include "fm_628.h"

inline int fm_628(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx168, bmats.Axx1792, bmats.Axx718, bmats.Axx840, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_1_1, bmats.B_1_12, bmats.B_1_14, bmats.Bx3005, bmats.Bx4240, bmats.Bx4619, bmats.Bx5734, bmats.Bx5735, bmats.Bx5736, bmats.Bx5737, bmats.Bx5738, bmats.Bx5739, bmats.Bx5740, bmats.Bx5741, bmats.Bx5742, bmats.Bx5743, bmats.Bx5744, bmats.Bx5745, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
