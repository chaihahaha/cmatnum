#include "stdafx.h"
#include "fm_11924.h"

int fm_11924(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_15_25, bmats.A_15_26, bmats.A_26_15, bmats.A_26_16, bmats.A_32_17, bmats.A_32_31, bmats.A_32_32, bmats.Ax2842, bmats.Ax5979, bmats.Ax703, };
    double A_coeffs[10] = {-1, 16, -1, 16, 1, -16, 1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_16_31, bmats.B_26_32, bmats.B_31_10, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_32_10.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
