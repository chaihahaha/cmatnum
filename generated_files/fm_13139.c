#include "stdafx.h"
#include "fm_13139.h"

int fm_13139(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_1, bmats.A_21_2, bmats.Ax4392, };
    double A_coeffs[3] = {-1, 16, -1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_21_18, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 17, &m.data[0][0], 1, &bmats.C_18_5.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_17.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_1_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_2_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_3_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_4_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_5_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_6_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_7_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_8_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_9_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_10_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_11_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_12_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_13_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_14_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_15_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_16_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_18.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_19.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_20.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_21.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_22.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_23.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_24.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_25.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_26.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_27.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_28.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_29.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_30.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_31.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
