#include "stdafx.h"
#include "fm_880.h"

inline int fm_880(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1002, bmats.Axx134, bmats.Axx1667, bmats.Axx1681, bmats.Axx1935, bmats.Axx2095, bmats.Axx2137, bmats.Axx2179, bmats.Axx2785, bmats.Axx2931, bmats.Axx3337, bmats.Axx3380, bmats.Axx4, bmats.Axx80, bmats.Axx824, bmats.Axx834, bmats.Axx942, bmats.Axx999, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_10_26, bmats.B_11_26, bmats.B_13_26, bmats.B_14_26, bmats.Bx3997, bmats.Bx4609, bmats.Bx8108, bmats.Bx8174, bmats.Bx8175, bmats.Bx8176, bmats.Bx8177, bmats.Bx8178, bmats.Bx8179, bmats.Bx8180, bmats.Bx8181, bmats.Bx8182, bmats.Bx8183, bmats.Bx8184, bmats.Bx8185, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
