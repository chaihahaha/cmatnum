#include "stdafx.h"
#include "fm_908.h"

int fm_908(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_17_26, bmats.A_26_17, bmats.A_26_26, bmats.Ax2963, };
    double A_coeffs[4] = {-17, 17, -17, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_17, bmats.B_17_18, bmats.B_17_19, bmats.B_17_20, bmats.B_17_21, bmats.B_17_22, bmats.B_17_23, bmats.B_17_24, bmats.B_17_25, bmats.B_17_26, bmats.B_17_27, bmats.B_17_28, bmats.B_17_29, bmats.B_17_30, bmats.B_17_31, bmats.B_17_32, bmats.B_18_26, bmats.B_19_26, bmats.B_20_26, bmats.B_21_26, bmats.B_22_26, bmats.B_23_26, bmats.B_24_26, bmats.B_25_26, bmats.B_26_17, bmats.B_26_26, bmats.B_27_26, bmats.B_28_26, bmats.B_29_26, bmats.B_30_26, bmats.B_31_26, bmats.B_32_26, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
