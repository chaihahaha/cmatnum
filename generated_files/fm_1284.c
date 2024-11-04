#include "stdafx.h"
#include "fm_1284.h"

int fm_1284(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_15, bmats.A_14_16, bmats.A_6_30, bmats.Ax1710, bmats.Ax392, bmats.Ax3987, };
    double A_coeffs[6] = {-1, -1, -16, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_11_22, bmats.B_14_22, bmats.B_15_22, bmats.B_16_22, bmats.B_1_22, bmats.B_2_22, bmats.B_30_1, bmats.B_3_22, bmats.B_4_22, bmats.B_5_22, bmats.B_6_14, bmats.B_6_22, bmats.Bx10907, bmats.Bx2491, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
