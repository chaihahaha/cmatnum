#include "stdafx.h"
#include "fm_998.h"

inline int fm_998(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1923, bmats.Axx3295, bmats.Axx520, bmats.Axx548, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_4_9, bmats.B_6_9, bmats.B_8_9, bmats.Bx7676, bmats.Bx8225, bmats.Bx8435, bmats.Bx9079, bmats.Bx9080, bmats.Bx9081, bmats.Bx9082, bmats.Bx9083, bmats.Bx9084, bmats.Bx9085, bmats.Bx9086, bmats.Bx9088, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
