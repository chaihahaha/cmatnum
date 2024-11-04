#include "stdafx.h"
#include "fm_1031.h"

int fm_1031(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_18_25, bmats.A_25_18, bmats.A_25_25, bmats.Ax3220, };
    double A_coeffs[4] = {-17, 17, -17, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_25, bmats.B_18_17, bmats.B_18_18, bmats.B_18_19, bmats.B_18_20, bmats.B_18_21, bmats.B_18_22, bmats.B_18_23, bmats.B_18_24, bmats.B_18_25, bmats.B_18_26, bmats.B_18_27, bmats.B_18_28, bmats.B_18_29, bmats.B_18_30, bmats.B_18_31, bmats.B_18_32, bmats.B_19_25, bmats.B_20_25, bmats.B_21_25, bmats.B_22_25, bmats.B_23_25, bmats.B_24_25, bmats.B_25_18, bmats.B_25_25, bmats.B_26_25, bmats.B_27_25, bmats.B_28_25, bmats.B_29_25, bmats.B_30_25, bmats.B_31_25, bmats.B_32_25, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
