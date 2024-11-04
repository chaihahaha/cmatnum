#include "stdafx.h"
#include "fm_534.h"

int fm_534(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_13, bmats.A_12_14, bmats.A_29_14, bmats.Ax1024, bmats.Ax2320, bmats.Ax983, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_11_12, bmats.B_12_12, bmats.B_13_12, bmats.B_14_12, bmats.B_1_12, bmats.B_28_13, bmats.B_2_12, bmats.B_5_12, bmats.Bx4620, bmats.Bx4641, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
