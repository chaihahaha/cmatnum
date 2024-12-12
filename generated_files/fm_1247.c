#include "stdafx.h"
#include "fm_1247.h"

inline int fm_1247(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2306, bmats.Axx3160, bmats.Axx822, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_22_22, bmats.B_6_23, bmats.Bx10561, bmats.Bx10619, bmats.Bx10620, bmats.Bx10621, bmats.Bx10622, bmats.Bx10623, bmats.Bx10624, bmats.Bx10625, bmats.Bx10626, bmats.Bx10627, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
