#include "stdafx.h"
#include "fm_780.h"

int fm_780(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_15_19, bmats.A_26_31, bmats.A_26_32, bmats.Ax1150, bmats.Ax2836, bmats.Ax627, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_31, bmats.B_17_26, bmats.B_18_26, bmats.B_19_26, bmats.B_20_26, bmats.B_21_26, bmats.B_22_26, bmats.B_23_26, bmats.B_24_26, bmats.B_25_26, bmats.B_26_26, bmats.B_27_26, bmats.B_28_26, bmats.B_29_26, bmats.B_30_26, bmats.B_31_1, bmats.B_31_10, bmats.B_31_11, bmats.B_31_12, bmats.B_31_13, bmats.B_31_14, bmats.B_31_15, bmats.B_31_16, bmats.B_31_2, bmats.B_31_26, bmats.B_31_3, bmats.B_31_4, bmats.B_31_5, bmats.B_31_6, bmats.B_31_7, bmats.B_31_8, bmats.B_31_9, bmats.B_32_26, };
    double B_coeffs[33] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
