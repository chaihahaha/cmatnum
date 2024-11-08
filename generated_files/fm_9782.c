#include "stdafx.h"
#include "fm_9782.h"

int fm_9782(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.Ax3157, };
    double A_coeffs[1] = {-1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.Bx13289, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_1_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_2_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_3_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_4_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_5_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_6_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_7_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_8_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_9_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_10_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_11_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_12_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_13_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_14_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_15_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_16_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
