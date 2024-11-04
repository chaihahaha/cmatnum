#include "stdafx.h"
#include "fm_1908.h"

int fm_1908(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_2_19, bmats.A_2_20, bmats.A_4_15, bmats.A_4_16, bmats.Ax4762, bmats.Ax588, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_20_10, bmats.B_20_11, bmats.B_20_12, bmats.B_20_13, bmats.B_20_14, bmats.B_20_6, bmats.B_20_7, bmats.B_20_8, bmats.B_20_9, bmats.B_2_4, bmats.B_6_18, bmats.B_9_18, bmats.Bx12536, bmats.Bx12805, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_18.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
