#include "stdafx.h"
#include "fm_15136.h"

int fm_15136(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_28_32, bmats.A_32_28, bmats.A_32_32, bmats.Ax7795, };
    double A_coeffs[4] = {-17, 17, -17, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_32, bmats.B_18_32, bmats.B_19_32, bmats.B_20_32, bmats.B_21_32, bmats.B_22_32, bmats.B_23_32, bmats.B_24_32, bmats.B_25_32, bmats.B_26_32, bmats.B_27_32, bmats.B_28_18, bmats.B_28_23, bmats.B_28_25, bmats.B_28_26, bmats.B_28_28, bmats.B_28_29, bmats.B_28_30, bmats.B_28_31, bmats.B_28_32, bmats.B_29_32, bmats.B_30_32, bmats.B_31_32, bmats.B_32_28, bmats.B_32_32, bmats.Bx6292, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
