#include "stdafx.h"
#include "fm_9991.h"

int fm_9991(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_31, bmats.A_25_32, bmats.Ax624, };
    double A_coeffs[3] = {16, -1, -1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_9_31, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_1.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_2.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_3.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_4.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_5.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_6.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_7.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_8.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_9.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_10.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_11.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_12.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_13.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_14.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_15.data[0][0], 1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_16.data[0][0], 1);
    cblas_daxpy(BL*BL, 17, &m.data[0][0], 1, &bmats.C_15_25.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_31.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
