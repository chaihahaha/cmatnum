#include "stdafx.h"
#include "fm_14012.h"

int fm_14012(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_6_7, bmats.A_6_8, bmats.A_7_1, bmats.A_7_10, bmats.A_7_11, bmats.A_7_12, bmats.A_7_13, bmats.A_7_14, bmats.A_7_15, bmats.A_7_16, bmats.A_7_2, bmats.A_7_3, bmats.A_7_4, bmats.A_7_5, bmats.A_7_6, bmats.A_7_7, bmats.A_7_8, bmats.A_7_9, bmats.Ax3470, };
    double A_coeffs[19] = {16, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 15, 15, -2, -2, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_7, bmats.B_7_6, bmats.B_7_7, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_6.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_7.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
