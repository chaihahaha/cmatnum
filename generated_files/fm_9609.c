#include "stdafx.h"
#include "fm_9609.h"

int fm_9609(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_10_15, bmats.A_10_16, bmats.A_15_3, bmats.A_15_4, bmats.A_3_10, bmats.A_3_9, bmats.Ax2932, bmats.Ax582, bmats.Ax944, };
    double A_coeffs[9] = {16, -1, 16, -1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_10_15, bmats.B_15_3, bmats.B_3_10, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_3.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_10.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
