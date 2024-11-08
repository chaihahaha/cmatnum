#include "stdafx.h"
#include "fm_1438.h"

int fm_1438(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_30, bmats.A_21_29, bmats.A_21_30, bmats.Ax1115, bmats.Ax1367, bmats.Ax4141, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_17_21, bmats.B_18_21, bmats.B_19_21, bmats.B_20_21, bmats.B_23_21, bmats.B_27_21, bmats.B_31_21, bmats.B_32_21, bmats.B_5_29, bmats.Bx11462, bmats.Bx3057, bmats.Bx4638, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_21.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
