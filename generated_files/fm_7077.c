#include "stdafx.h"
#include "fm_7077.h"

int fm_7077(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_16_29, bmats.A_16_30, bmats.A_21_17, bmats.A_21_18, bmats.A_21_19, bmats.A_21_20, bmats.A_21_21, bmats.A_21_22, bmats.A_21_31, bmats.A_21_32, bmats.A_30_5, bmats.A_30_6, bmats.Ax1625, bmats.Ax399, bmats.Ax6068, };
    double A_coeffs[15] = {-1, 16, 1, 1, 1, 1, 1, 1, 1, -16, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_30_21, bmats.B_32_14, bmats.B_5_32, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_14.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_21.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
