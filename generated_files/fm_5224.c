#include "stdafx.h"
#include "fm_5224.h"

int fm_5224(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_10_10, bmats.A_10_3, bmats.A_10_4, bmats.A_15_25, bmats.A_15_26, bmats.A_20_15, bmats.A_20_16, bmats.Ax2842, bmats.Ax5716, bmats.Ax709, };
    double A_coeffs[10] = {1, 1, -16, -1, 16, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_10, bmats.B_26_4, bmats.B_4_31, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_4.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_10.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_10_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
