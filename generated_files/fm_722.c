#include "stdafx.h"
#include "fm_722.h"

inline int fm_722(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1641, bmats.Axx3366, bmats.Axx3395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx5650, bmats.Bx6615, bmats.Bx6642, bmats.Bx6643, bmats.Bx6644, bmats.Bx6645, bmats.Bx6646, bmats.Bx6647, bmats.Bx6648, bmats.Bx6649, bmats.Bx6650, bmats.Bx6651, bmats.Bx6652, bmats.Bx6653, bmats.Bx6654, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
