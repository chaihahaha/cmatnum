#include "stdafx.h"
#include "fm_473.h"

inline int fm_473(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1495, bmats.Axx2993, bmats.Axx690, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_24_13, bmats.B_30_13, bmats.Bx3034, bmats.Bx3134, bmats.Bx3808, bmats.Bx3823, bmats.Bx3824, bmats.Bx3825, bmats.Bx3826, bmats.Bx3827, bmats.Bx3828, bmats.Bx3829, bmats.Bx3830, bmats.Bx3831, bmats.Bx3832, bmats.Bx3833, bmats.Bx3834, bmats.Bx3835, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
