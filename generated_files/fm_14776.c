#include "stdafx.h"
#include "fm_14776.h"

int fm_14776(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_15_15, bmats.A_15_16, bmats.A_16_15, bmats.A_16_16, bmats.A_31_5, bmats.A_31_6, bmats.A_6_31, bmats.A_6_32, bmats.Ax3967, bmats.Ax463, bmats.Ax649, bmats.Ax654, bmats.Ax784, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_15_22, bmats.B_6_1, bmats.B_6_10, bmats.B_6_11, bmats.B_6_12, bmats.B_6_13, bmats.B_6_14, bmats.B_6_15, bmats.B_6_16, bmats.B_6_2, bmats.B_6_3, bmats.B_6_4, bmats.B_6_5, bmats.B_6_6, bmats.B_6_7, bmats.B_6_8, bmats.B_6_9, bmats.Bx13385, };
    double B_coeffs[18] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
