#include "stdafx.h"
#include "fm_8773.h"

int fm_8773(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_11_29, bmats.A_11_30, bmats.A_22_17, bmats.A_22_22, bmats.A_22_27, bmats.A_22_28, bmats.A_29_5, bmats.A_29_6, bmats.Ax2077, bmats.Ax402, bmats.Ax6425, };
    double A_coeffs[11] = {16, -1, 1, 1, -16, 1, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_27_13, bmats.B_29_22, bmats.B_6_27, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_22_13.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_22.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
