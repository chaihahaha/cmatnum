#include "stdafx.h"
#include "fm_15130.h"

int fm_15130(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_16_27, bmats.A_16_28, bmats.A_27_15, bmats.A_27_16, bmats.A_28_31, bmats.A_28_32, bmats.A_32_31, bmats.A_32_32, bmats.Ax2282, bmats.Ax533, bmats.Ax612, bmats.Ax685, bmats.Ax7795, };
    double A_coeffs[13] = {16, -1, -1, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_15_32, bmats.B_16_32, bmats.B_27_17, bmats.B_27_18, bmats.B_27_23, bmats.B_32_11, bmats.Bx13238, bmats.Bx7425, };
    double B_coeffs[8] = {-1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
