#include "stdafx.h"
#include "fm_520.h"

inline int fm_520(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2110, bmats.Axx2148, bmats.Axx794, bmats.Axx800, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_13, bmats.B_2_13, bmats.Bx3071, bmats.Bx3895, bmats.Bx4495, bmats.Bx4496, bmats.Bx4497, bmats.Bx4498, bmats.Bx4499, bmats.Bx4500, bmats.Bx4501, bmats.Bx4502, bmats.Bx4503, bmats.Bx4504, bmats.Bx4505, bmats.Bx4507, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
