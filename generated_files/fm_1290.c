#include "stdafx.h"
#include "fm_1290.h"

int fm_1290(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_15_19, bmats.A_22_31, bmats.A_22_32, bmats.Ax1150, bmats.Ax3987, bmats.Ax639, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_17_22, bmats.B_18_22, bmats.B_19_22, bmats.B_20_22, bmats.B_21_22, bmats.B_23_22, bmats.B_30_22, bmats.B_31_1, bmats.B_31_10, bmats.B_31_11, bmats.B_31_12, bmats.B_31_13, bmats.B_31_14, bmats.B_31_15, bmats.B_31_16, bmats.B_31_2, bmats.B_31_22, bmats.B_31_3, bmats.B_31_4, bmats.B_31_5, bmats.B_31_6, bmats.B_31_7, bmats.B_31_8, bmats.B_31_9, bmats.B_32_22, bmats.B_6_31, bmats.Bx10896, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
