#include "stdafx.h"
#include "fm_1353.h"

int fm_1353(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_21_22, bmats.A_22_21, bmats.A_26_21, bmats.A_26_22, bmats.Ax4018, bmats.Ax42, };
    double A_coeffs[6] = {-17, 17, 1, -16, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_22, bmats.B_18_22, bmats.B_19_22, bmats.B_20_22, bmats.B_21_17, bmats.B_21_18, bmats.B_21_19, bmats.B_21_20, bmats.B_21_21, bmats.B_21_22, bmats.B_21_23, bmats.B_21_24, bmats.B_21_25, bmats.B_21_26, bmats.B_21_27, bmats.B_21_28, bmats.B_21_29, bmats.B_21_30, bmats.B_21_31, bmats.B_21_32, bmats.B_22_21, bmats.B_22_22, bmats.B_23_22, bmats.B_24_22, bmats.B_25_22, bmats.B_26_22, bmats.B_27_22, bmats.B_28_22, bmats.B_29_22, bmats.B_30_22, bmats.B_31_22, bmats.B_32_22, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
