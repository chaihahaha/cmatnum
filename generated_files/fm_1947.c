#include "stdafx.h"
#include "fm_1947.h"

int fm_1947(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_17, bmats.A_17_18, bmats.A_18_17, bmats.A_18_18, bmats.A_1_29, bmats.A_1_30, bmats.A_29_15, bmats.A_29_16, bmats.Ax158, bmats.Ax441, bmats.Ax4655, bmats.Ax4793, bmats.Ax691, };
    double A_coeffs[13] = {16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_16_17, bmats.B_17_13, bmats.B_1_17, bmats.B_29_27, bmats.B_29_28, bmats.B_29_29, bmats.B_29_30, bmats.B_29_31, bmats.B_29_32, bmats.B_2_17, bmats.Bx12860, bmats.Bx4622, };
    double B_coeffs[12] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_17.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
