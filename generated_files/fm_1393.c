#include "stdafx.h"
#include "fm_1393.h"

int fm_1393(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_19_21, bmats.A_19_22, bmats.A_20_22, bmats.A_22_20, bmats.Ax3946, bmats.Ax4094, };
    double A_coeffs[6] = {1, -16, -17, 17, 1, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_22, bmats.B_18_22, bmats.B_19_22, bmats.B_20_17, bmats.B_20_18, bmats.B_20_19, bmats.B_20_20, bmats.B_20_21, bmats.B_20_22, bmats.B_20_23, bmats.B_20_24, bmats.B_20_25, bmats.B_20_26, bmats.B_20_27, bmats.B_20_28, bmats.B_20_29, bmats.B_20_30, bmats.B_20_31, bmats.B_20_32, bmats.B_21_22, bmats.B_22_20, bmats.B_23_22, bmats.B_30_22, bmats.B_31_22, bmats.B_32_22, bmats.Bx10896, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
