#include "stdafx.h"
#include "fm_3630.h"

int fm_3630(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_13_10, bmats.A_13_29, bmats.A_13_30, bmats.A_13_9, bmats.A_26_13, bmats.A_26_14, bmats.Ax408, bmats.Ax509, bmats.Ax5301, };
    double A_coeffs[9] = {-16, 16, -1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_10_29, bmats.B_13_13, bmats.B_29_10, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_10.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_13.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_13_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
