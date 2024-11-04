#include "stdafx.h"
#include "fm_486.h"

int fm_486(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_19, bmats.A_13_20, bmats.A_3_15, bmats.A_3_16, bmats.Ax2154, bmats.Ax585, };
    double A_coeffs[6] = {-16, 1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_29, bmats.B_11_29, bmats.B_12_29, bmats.B_13_29, bmats.B_13_3, bmats.B_14_29, bmats.B_15_29, bmats.B_16_29, bmats.B_19_1, bmats.B_19_10, bmats.B_19_11, bmats.B_19_12, bmats.B_19_13, bmats.B_19_14, bmats.B_19_15, bmats.B_19_16, bmats.B_19_2, bmats.B_19_3, bmats.B_19_4, bmats.B_19_5, bmats.B_19_6, bmats.B_19_7, bmats.B_19_8, bmats.B_19_9, bmats.B_1_29, bmats.B_2_29, bmats.B_3_29, bmats.B_4_29, bmats.B_5_29, bmats.B_6_29, bmats.B_7_29, bmats.B_8_29, bmats.B_9_29, };
    double B_coeffs[33] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
