#include "stdafx.h"
#include "fm_1398.h"

int fm_1398(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 5;
    double_cmat A_mats[5] = {bmats.A_5_13, bmats.A_5_14, bmats.Ax1048, bmats.Ax1900, bmats.Ax4126, };
    double A_coeffs[5] = {1, -16, 1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_12_5, bmats.B_14_17, bmats.B_14_5, bmats.B_15_5, bmats.B_21_14, bmats.B_4_5, bmats.B_7_5, bmats.B_9_5, bmats.Bx11433, bmats.Bx2496, };
    double B_coeffs[10] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
