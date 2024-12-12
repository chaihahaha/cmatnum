#include "stdafx.h"
#include "fm_1310.h"

inline int fm_1310(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1033, bmats.Axx2090, bmats.Axx392, bmats.Axx432, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_12_6, bmats.B_13_6, bmats.B_7_6, bmats.Bx11043, bmats.Bx11047, bmats.Bx2887, bmats.Bx6197, bmats.Bx7431, bmats.Bx9696, };
    double B_coeffs[9] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
