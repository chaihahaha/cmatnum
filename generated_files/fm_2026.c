#include "stdafx.h"
#include "fm_2026.h"

int fm_2026(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_1_5, bmats.A_4_1, bmats.A_4_2, bmats.A_5_1, bmats.Ax4533, bmats.Ax4836, };
    double A_coeffs[6] = {17, -16, 1, -17, 1, 1, };
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_14_1, bmats.B_15_1, bmats.B_16_1, bmats.B_1_5, bmats.B_4_1, bmats.B_5_1, bmats.B_5_10, bmats.B_5_11, bmats.B_5_12, bmats.B_5_13, bmats.B_5_14, bmats.B_5_15, bmats.B_5_16, bmats.B_5_2, bmats.B_5_3, bmats.B_5_4, bmats.B_5_5, bmats.B_5_6, bmats.B_5_7, bmats.B_5_8, bmats.B_5_9, bmats.B_6_1, bmats.B_7_1, bmats.Bx12870, };
    double B_coeffs[24] = {-1, -1, -1, 1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_1.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
