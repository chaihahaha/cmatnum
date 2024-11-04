#include "stdafx.h"
#include "fm_14678.h"

int fm_14678(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_21_10, bmats.A_21_9, bmats.A_26_18, bmats.A_26_19, bmats.A_26_20, bmats.A_26_26, bmats.A_26_28, bmats.A_26_29, bmats.A_26_30, bmats.A_4_21, bmats.A_4_22, bmats.Ax2816, bmats.Ax3865, bmats.Ax8334, };
    double A_coeffs[14] = {16, -1, 1, 1, -16, 1, 1, 1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_10_20, bmats.B_20_5, bmats.B_21_26, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_26_5.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_20.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
