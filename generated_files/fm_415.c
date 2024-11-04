#include "stdafx.h"
#include "fm_415.h"

int fm_415(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_18_29, bmats.A_18_30, bmats.A_29_21, bmats.A_29_29, bmats.Ax1106, bmats.Ax1834, bmats.Ax2023, };
    double A_coeffs[7] = {-16, 1, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_17_29, bmats.B_18_29, bmats.B_19_29, bmats.B_20_29, bmats.B_21_29, bmats.B_22_29, bmats.B_23_29, bmats.B_24_29, bmats.B_25_29, bmats.B_26_29, bmats.B_27_29, bmats.B_28_29, bmats.B_29_17, bmats.B_29_18, bmats.B_29_19, bmats.B_29_20, bmats.B_29_21, bmats.B_29_22, bmats.B_29_23, bmats.B_29_24, bmats.B_29_25, bmats.B_29_26, bmats.B_29_27, bmats.B_29_28, bmats.B_29_29, bmats.B_29_30, bmats.B_29_31, bmats.B_29_32, bmats.B_30_29, bmats.B_31_29, bmats.B_32_29, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
