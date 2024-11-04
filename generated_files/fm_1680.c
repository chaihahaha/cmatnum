#include "stdafx.h"
#include "fm_1680.h"

int fm_1680(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_14_3, bmats.A_14_4, bmats.A_15_3, bmats.A_3_15, bmats.Ax1590, bmats.Ax4552, };
    double A_coeffs[6] = {-16, 1, -17, 17, 1, 1, };
    int n_B_mats = 23;
    double_cmat B_mats[23] = {bmats.B_14_3, bmats.B_15_1, bmats.B_15_10, bmats.B_15_11, bmats.B_15_12, bmats.B_15_13, bmats.B_15_14, bmats.B_15_15, bmats.B_15_16, bmats.B_15_2, bmats.B_15_3, bmats.B_15_4, bmats.B_15_5, bmats.B_15_6, bmats.B_15_7, bmats.B_15_8, bmats.B_15_9, bmats.B_16_3, bmats.B_1_3, bmats.B_2_3, bmats.B_3_15, bmats.B_6_3, bmats.Bx12291, };
    double B_coeffs[23] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_3.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
