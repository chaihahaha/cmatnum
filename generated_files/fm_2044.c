#include "stdafx.h"
#include "fm_2044.h"

int fm_2044(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_17_14, bmats.A_1_1, bmats.A_1_2, bmats.Ax4647, bmats.Ax4775, bmats.Ax808, };
    double A_coeffs[6] = {-1, -16, 1, 1, 1, 1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_14_1, bmats.B_15_1, bmats.B_16_1, bmats.B_17_1, bmats.B_1_17, bmats.B_1_18, bmats.B_1_19, bmats.B_1_20, bmats.B_1_21, bmats.B_1_22, bmats.B_1_23, bmats.B_1_24, bmats.B_1_25, bmats.B_1_26, bmats.B_1_27, bmats.B_1_28, bmats.B_1_29, bmats.B_1_30, bmats.B_1_31, bmats.B_1_32, bmats.B_4_1, bmats.B_5_1, bmats.B_6_1, bmats.B_7_1, bmats.Bx12870, };
    double B_coeffs[25] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_1.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
