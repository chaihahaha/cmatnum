#include "stdafx.h"
#include "fm_13309.h"

int fm_13309(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_16_15, bmats.A_16_16, bmats.A_31_3, bmats.Ax1152, bmats.Ax463, bmats.Ax7798, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_10_16, bmats.B_12_16, bmats.B_15_16, bmats.B_15_17, bmats.B_15_18, bmats.B_15_19, bmats.B_15_20, bmats.B_15_21, bmats.B_15_22, bmats.B_15_23, bmats.B_15_24, bmats.B_15_25, bmats.B_15_26, bmats.B_15_27, bmats.B_15_28, bmats.B_15_29, bmats.B_15_30, bmats.B_15_31, bmats.B_15_32, bmats.B_1_16, bmats.B_2_16, bmats.B_32_15, bmats.B_3_16, bmats.B_5_16, bmats.B_8_16, bmats.B_9_16, bmats.Bx13355, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
