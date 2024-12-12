#include "stdafx.h"
#include "fm_1251.h"

inline int fm_1251(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2793, bmats.Axx2795, bmats.Axx895, bmats.Axx944, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.Bx10526, bmats.Bx10606, bmats.Bx10646, bmats.Bx10656, bmats.Bx10657, bmats.Bx10658, bmats.Bx10659, bmats.Bx10660, bmats.Bx10661, bmats.Bx10662, bmats.Bx10663, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
