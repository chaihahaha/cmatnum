#include "stdafx.h"
#include "fm_13526.h"

int fm_13526(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_12_13, bmats.A_12_14, bmats.A_14_1, bmats.A_14_10, bmats.A_14_11, bmats.A_14_12, bmats.A_14_13, bmats.A_14_14, bmats.A_14_15, bmats.A_14_16, bmats.A_14_2, bmats.A_14_3, bmats.A_14_4, bmats.A_14_5, bmats.A_14_6, bmats.A_14_7, bmats.A_14_8, bmats.A_14_9, bmats.Ax1024, };
    double A_coeffs[19] = {-1, 16, -2, -2, -2, 15, -2, 15, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_14, bmats.B_14_12, bmats.B_14_14, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_12.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_14.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
