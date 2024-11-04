#include "stdafx.h"
#include "fm_1743.h"

int fm_1743(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_20_15, bmats.A_3_3, bmats.A_3_4, bmats.Ax1608, bmats.Ax4339, bmats.Ax4519, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_11_3, bmats.B_12_3, bmats.B_14_3, bmats.B_19_4, bmats.B_1_3, bmats.B_4_17, bmats.B_4_18, bmats.B_4_19, bmats.B_4_20, bmats.B_4_21, bmats.B_4_22, bmats.B_4_23, bmats.B_4_24, bmats.B_4_25, bmats.B_4_26, bmats.B_4_27, bmats.B_4_28, bmats.B_4_29, bmats.B_4_30, bmats.B_4_31, bmats.B_4_32, bmats.B_5_3, bmats.B_7_3, bmats.B_9_3, bmats.Bx12416, };
    double B_coeffs[25] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_3.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
