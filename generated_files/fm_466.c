#include "stdafx.h"
#include "fm_466.h"

inline int fm_466(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1043, bmats.Axx1672, bmats.Axx2856, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_7_29, bmats.Bx3180, bmats.Bx3722, bmats.Bx3723, bmats.Bx3724, bmats.Bx3725, bmats.Bx3726, bmats.Bx3727, bmats.Bx3728, bmats.Bx3729, bmats.Bx3730, bmats.Bx3731, bmats.Bx3732, bmats.Bx3733, bmats.Bx3734, bmats.Bx3735, bmats.Bx3737, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
