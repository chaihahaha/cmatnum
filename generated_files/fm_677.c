#include "stdafx.h"
#include "fm_677.h"

int fm_677(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_11_15, bmats.A_11_16, bmats.A_3_11, bmats.A_3_12, bmats.Ax2208, bmats.Ax2558, bmats.Ax2694, };
    double A_coeffs[7] = {-1, -1, -16, 1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_10_11, bmats.B_11_1, bmats.B_11_10, bmats.B_11_11, bmats.B_11_12, bmats.B_11_13, bmats.B_11_14, bmats.B_11_15, bmats.B_11_16, bmats.B_11_2, bmats.B_11_3, bmats.B_11_4, bmats.B_11_5, bmats.B_11_6, bmats.B_11_7, bmats.B_11_8, bmats.B_11_9, bmats.B_12_11, bmats.B_13_11, bmats.B_14_11, bmats.B_15_11, bmats.B_16_11, bmats.B_1_11, bmats.B_2_11, bmats.B_3_11, bmats.B_4_11, bmats.B_5_11, bmats.B_6_11, bmats.B_7_11, bmats.B_8_11, bmats.B_9_11, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
