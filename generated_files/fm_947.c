#include "stdafx.h"
#include "fm_947.h"

int fm_947(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_25_10, bmats.A_25_31, bmats.A_25_32, bmats.A_25_9, bmats.Ax3292, bmats.Ax624, };
    double A_coeffs[6] = {1, -1, -1, -16, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_9, bmats.B_18_9, bmats.B_19_9, bmats.B_20_9, bmats.B_21_9, bmats.B_22_9, bmats.B_23_9, bmats.B_24_9, bmats.B_25_25, bmats.B_25_9, bmats.B_26_9, bmats.B_27_9, bmats.B_28_9, bmats.B_29_9, bmats.B_30_9, bmats.B_31_9, bmats.B_32_9, bmats.B_9_17, bmats.B_9_18, bmats.B_9_19, bmats.B_9_20, bmats.B_9_21, bmats.B_9_22, bmats.B_9_23, bmats.B_9_24, bmats.B_9_25, bmats.B_9_26, bmats.B_9_27, bmats.B_9_28, bmats.B_9_29, bmats.B_9_30, bmats.B_9_31, bmats.B_9_32, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
