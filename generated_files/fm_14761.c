#include "stdafx.h"
#include "fm_14761.h"

int fm_14761(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_15_19, bmats.A_15_20, bmats.A_20_15, bmats.A_20_16, bmats.A_31_31, bmats.A_31_32, bmats.A_32_31, bmats.A_32_32, bmats.Ax533, bmats.Ax664, bmats.Ax669, bmats.Ax709, bmats.Ax918, };
    double A_coeffs[13] = {-1, 16, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_14_31, bmats.B_20_17, bmats.B_20_18, bmats.B_20_19, bmats.B_20_20, bmats.B_20_21, bmats.B_20_22, bmats.B_20_23, bmats.B_20_24, bmats.B_20_25, bmats.B_20_26, bmats.B_20_27, bmats.B_20_28, bmats.B_20_29, bmats.B_20_30, bmats.B_20_31, bmats.B_20_32, bmats.B_31_4, bmats.Bx13226, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
