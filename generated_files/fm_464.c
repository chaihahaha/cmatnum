#include "stdafx.h"
#include "fm_464.h"

inline int fm_464(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1457, bmats.Axx2450, bmats.Axx260, bmats.Axx274, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_23_29, bmats.Bx2115, bmats.Bx2493, bmats.Bx3692, bmats.Bx3693, bmats.Bx3694, bmats.Bx3695, bmats.Bx3696, bmats.Bx3697, bmats.Bx3698, bmats.Bx3699, bmats.Bx3700, bmats.Bx3701, bmats.Bx3702, bmats.Bx3703, bmats.Bx3704, bmats.Bx3705, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
