#include "stdafx.h"
#include "fm_529.h"

inline int fm_529(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2129, bmats.Axx553, bmats.Axx814, bmats.Axx856, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_13_12, bmats.Bx4241, bmats.Bx4611, bmats.Bx4612, bmats.Bx4613, bmats.Bx4614, bmats.Bx4615, bmats.Bx4617, bmats.Bx4620, };
    double B_coeffs[9] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
