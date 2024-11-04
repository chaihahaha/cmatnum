#include "stdafx.h"
#include "fm_14052.h"

int fm_14052(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_1_1, bmats.A_1_2, bmats.A_2_1, bmats.A_2_10, bmats.A_2_11, bmats.A_2_12, bmats.A_2_13, bmats.A_2_14, bmats.A_2_15, bmats.A_2_16, bmats.A_2_2, bmats.A_2_3, bmats.A_2_4, bmats.A_2_5, bmats.A_2_6, bmats.A_2_7, bmats.A_2_8, bmats.A_2_9, bmats.Ax4647, };
    double A_coeffs[19] = {-1, 16, 15, -2, -2, -2, -2, -2, -2, -2, 15, -2, -2, -2, -2, -2, -2, -2, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_2, bmats.B_2_1, bmats.B_2_2, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_1.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_2.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
