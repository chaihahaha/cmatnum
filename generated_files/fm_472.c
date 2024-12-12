#include "stdafx.h"
#include "fm_472.h"

inline int fm_472(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1457, bmats.Axx259, bmats.Axx275, bmats.Axx499, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_24_29, bmats.Bx1494, bmats.Bx2493, bmats.Bx3181, bmats.Bx3810, bmats.Bx3811, bmats.Bx3812, bmats.Bx3813, bmats.Bx3814, bmats.Bx3815, bmats.Bx3816, bmats.Bx3817, bmats.Bx3818, bmats.Bx3819, bmats.Bx3820, bmats.Bx3821, bmats.Bx3822, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
