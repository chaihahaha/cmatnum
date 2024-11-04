#include "stdafx.h"
#include "fm_14930.h"

int fm_14930(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_32_25, bmats.A_32_26, bmats.A_9_30, bmats.Ax1512, bmats.Ax2952, bmats.Ax7799, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_16_25, bmats.B_21_32, bmats.B_22_32, bmats.B_23_32, bmats.B_24_32, bmats.B_25_10, bmats.B_25_11, bmats.B_25_12, bmats.B_25_13, bmats.B_25_14, bmats.B_25_15, bmats.B_25_16, bmats.B_25_9, bmats.B_30_32, bmats.B_31_32, bmats.B_32_32, bmats.Bx13349, bmats.Bx9525, };
    double B_coeffs[18] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
