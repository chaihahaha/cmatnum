#include "stdafx.h"
#include "fm_958.h"

int fm_958(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_11_31, bmats.A_11_32, bmats.A_25_11, bmats.A_25_12, bmats.A_2_10, bmats.A_2_9, bmats.A_9_10, bmats.A_9_9, bmats.Ax2242, bmats.Ax2923, bmats.Ax2944, bmats.Ax3213, bmats.Ax754, };
    double A_coeffs[13] = {-1, -1, 16, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_11_1, bmats.B_11_10, bmats.B_11_11, bmats.B_11_12, bmats.B_11_13, bmats.B_11_14, bmats.B_11_15, bmats.B_11_16, bmats.B_11_2, bmats.B_11_3, bmats.B_11_4, bmats.B_11_5, bmats.B_11_6, bmats.B_11_7, bmats.B_11_8, bmats.B_11_9, bmats.B_17_9, bmats.B_18_9, bmats.B_19_9, bmats.B_20_9, bmats.B_21_9, bmats.B_22_9, bmats.B_23_9, bmats.B_24_9, bmats.B_25_9, bmats.B_26_9, bmats.B_27_9, bmats.B_28_9, bmats.B_29_9, bmats.B_30_9, bmats.B_31_9, bmats.B_32_9, bmats.B_9_27, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
