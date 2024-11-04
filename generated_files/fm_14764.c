#include "stdafx.h"
#include "fm_14764.h"

int fm_14764(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_15_20, bmats.A_15_21, bmats.A_4_15, bmats.A_4_16, bmats.Ax588, bmats.Ax8474, };
    double A_coeffs[6] = {-16, 1, -1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_14_31, bmats.B_15_4, bmats.B_20_1, bmats.B_20_10, bmats.B_20_11, bmats.B_20_12, bmats.B_20_13, bmats.B_20_14, bmats.B_20_15, bmats.B_20_16, bmats.B_20_2, bmats.B_20_3, bmats.B_20_4, bmats.B_20_5, bmats.B_20_6, bmats.B_20_7, bmats.B_20_8, bmats.B_20_9, bmats.Bx13226, };
    double B_coeffs[19] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
