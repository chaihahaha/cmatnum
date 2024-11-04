#include "stdafx.h"
#include "fm_1786.h"

int fm_1786(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_19_1, bmats.A_19_10, bmats.A_19_11, bmats.A_19_12, bmats.A_19_13, bmats.A_19_14, bmats.A_19_15, bmats.A_19_16, bmats.A_19_2, bmats.A_19_3, bmats.A_19_31, bmats.A_19_32, bmats.A_19_4, bmats.A_19_5, bmats.A_19_6, bmats.A_19_7, bmats.A_19_8, bmats.A_19_9, bmats.Ax4519, bmats.Ax630, };
    double A_coeffs[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, -16, -1, -1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_3, bmats.B_18_3, bmats.B_19_19, bmats.B_19_3, bmats.B_20_3, bmats.B_21_3, bmats.B_22_3, bmats.B_23_3, bmats.B_24_3, bmats.B_25_3, bmats.B_26_3, bmats.B_27_3, bmats.B_28_3, bmats.B_29_3, bmats.B_30_3, bmats.B_31_3, bmats.B_32_3, bmats.B_3_17, bmats.B_3_18, bmats.B_3_19, bmats.B_3_20, bmats.B_3_21, bmats.B_3_22, bmats.B_3_23, bmats.B_3_24, bmats.B_3_25, bmats.B_3_26, bmats.B_3_27, bmats.B_3_28, bmats.B_3_29, bmats.B_3_30, bmats.B_3_31, bmats.B_3_32, };
    double B_coeffs[33] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_3.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
