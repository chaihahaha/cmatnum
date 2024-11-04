#include "stdafx.h"
#include "fm_1638.h"

int fm_1638(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_20_1, bmats.A_20_5, bmats.A_21_31, bmats.A_21_32, bmats.Ax4471, bmats.Ax636, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_17_4, bmats.B_18_4, bmats.B_19_4, bmats.B_20_21, bmats.B_20_4, bmats.B_31_4, bmats.B_32_4, bmats.B_5_17, bmats.B_5_18, bmats.B_5_19, bmats.B_5_20, bmats.B_5_21, bmats.B_5_22, bmats.B_5_23, bmats.B_5_24, bmats.B_5_25, bmats.B_5_26, bmats.B_5_27, bmats.B_5_28, bmats.B_5_29, bmats.B_5_30, bmats.B_5_31, bmats.B_5_32, bmats.Bx11923, };
    double B_coeffs[24] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
