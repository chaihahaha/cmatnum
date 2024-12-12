#include "stdafx.h"
#include "fm_844.h"

inline int fm_844(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1600, bmats.Axx1967, bmats.Axx2622, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx5536, bmats.Bx6896, bmats.Bx7187, bmats.Bx7773, bmats.Bx7774, bmats.Bx7775, bmats.Bx7776, bmats.Bx7777, bmats.Bx7778, bmats.Bx7779, bmats.Bx7780, bmats.Bx7781, bmats.Bx7782, bmats.Bx7783, bmats.Bx7784, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
