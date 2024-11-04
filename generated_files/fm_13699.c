#include "stdafx.h"
#include "fm_13699.h"

int fm_13699(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_12_1, bmats.A_12_10, bmats.A_12_11, bmats.A_12_12, bmats.A_12_13, bmats.A_12_14, bmats.A_12_15, bmats.A_12_16, bmats.A_12_2, bmats.A_12_3, bmats.A_12_4, bmats.A_12_5, bmats.A_12_6, bmats.A_12_7, bmats.A_12_8, bmats.A_12_9, bmats.A_6_11, bmats.A_6_12, bmats.Ax2193, };
    double A_coeffs[19] = {-2, -2, -2, 15, -2, -2, -2, -2, -2, -2, -2, -2, 15, -2, -2, -2, -1, 16, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_12, bmats.B_12_6, bmats.B_6_12, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_6.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_12.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
