#include "stdafx.h"
#include "fm_1551.h"

int fm_1551(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_13_31, bmats.A_13_32, bmats.A_20_13, bmats.A_20_14, bmats.A_3_3, bmats.A_3_4, bmats.A_4_3, bmats.A_4_4, bmats.Ax4339, bmats.Ax4363, bmats.Ax4368, bmats.Ax518, bmats.Ax760, };
    double A_coeffs[13] = {-1, -1, 16, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_13_11, bmats.B_13_12, bmats.B_13_14, bmats.B_13_15, bmats.B_13_16, bmats.B_13_2, bmats.B_13_5, bmats.B_17_4, bmats.B_18_4, bmats.B_19_4, bmats.B_20_4, bmats.B_31_4, bmats.B_32_4, bmats.B_4_29, bmats.Bx11923, bmats.Bx4615, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
