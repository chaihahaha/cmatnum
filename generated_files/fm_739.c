#include "stdafx.h"
#include "fm_739.h"

int fm_739(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_11_5, bmats.A_11_6, bmats.A_22_16, bmats.Ax1730, bmats.Ax2627, bmats.Ax2786, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_11, bmats.B_11_11, bmats.B_12_11, bmats.B_13_11, bmats.B_14_11, bmats.B_15_11, bmats.B_16_11, bmats.B_1_11, bmats.B_27_6, bmats.B_2_11, bmats.B_3_11, bmats.B_4_11, bmats.B_5_11, bmats.B_6_11, bmats.B_6_17, bmats.B_6_18, bmats.B_6_19, bmats.B_6_20, bmats.B_6_21, bmats.B_6_22, bmats.B_6_23, bmats.B_6_24, bmats.B_6_25, bmats.B_6_26, bmats.B_6_27, bmats.B_6_28, bmats.B_6_29, bmats.B_6_30, bmats.B_6_31, bmats.B_6_32, bmats.B_7_11, bmats.B_8_11, bmats.B_9_11, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
