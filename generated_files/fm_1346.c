#include "stdafx.h"
#include "fm_1346.h"

int fm_1346(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_21, bmats.A_17_22, bmats.A_22_21, bmats.A_22_22, bmats.A_26_15, bmats.A_26_16, bmats.A_6_25, bmats.A_6_26, bmats.Ax204, bmats.Ax2857, bmats.Ax3940, bmats.Ax3960, bmats.Ax703, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_11_22, bmats.B_14_22, bmats.B_15_22, bmats.B_16_22, bmats.B_1_22, bmats.B_22_10, bmats.B_26_17, bmats.B_26_18, bmats.B_26_19, bmats.B_26_20, bmats.B_26_21, bmats.B_26_22, bmats.B_2_22, bmats.B_3_22, bmats.B_4_22, bmats.B_5_22, bmats.B_6_22, bmats.Bx10907, bmats.Bx7697, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
