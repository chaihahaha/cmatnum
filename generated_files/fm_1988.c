#include "stdafx.h"
#include "fm_1988.h"

int fm_1988(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_17, bmats.A_17_18, bmats.A_18_17, bmats.A_18_18, bmats.A_1_21, bmats.A_1_22, bmats.A_22_15, bmats.A_22_16, bmats.Ax158, bmats.Ax3856, bmats.Ax4655, bmats.Ax4793, bmats.Ax715, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_16_17, bmats.B_17_6, bmats.B_1_17, bmats.B_22_17, bmats.B_22_18, bmats.B_22_19, bmats.B_22_20, bmats.B_22_21, bmats.B_22_22, bmats.B_22_23, bmats.B_22_24, bmats.B_22_25, bmats.B_22_26, bmats.B_22_27, bmats.B_22_28, bmats.B_22_29, bmats.B_22_30, bmats.B_22_31, bmats.B_22_32, bmats.B_2_17, bmats.Bx12860, };
    double B_coeffs[21] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_17.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
