#include "stdafx.h"
#include "fm_1911.h"

int fm_1911(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_15_1, bmats.A_16_1, bmats.A_16_2, bmats.A_1_15, bmats.Ax4644, bmats.Ax4781, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_14_1, bmats.B_15_1, bmats.B_15_11, bmats.B_15_12, bmats.B_15_13, bmats.B_15_2, bmats.B_16_1, bmats.B_1_15, bmats.B_4_1, bmats.B_5_1, bmats.B_6_1, bmats.B_7_1, bmats.Bx12682, bmats.Bx12870, };
    double B_coeffs[14] = {-1, -2, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_1.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
