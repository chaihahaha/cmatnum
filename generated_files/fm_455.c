#include "stdafx.h"
#include "fm_455.h"

inline int fm_455(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1795, bmats.Axx1816, bmats.Axx393, bmats.Axx435, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_6_13, bmats.Bx3559, bmats.Bx3560, bmats.Bx3561, bmats.Bx3562, bmats.Bx3563, bmats.Bx3564, bmats.Bx3565, bmats.Bx3566, bmats.Bx3567, bmats.Bx3568, bmats.Bx3569, bmats.Bx3570, bmats.Bx3571, bmats.Bx3572, bmats.Bx3574, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
