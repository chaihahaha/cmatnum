#include "stdafx.h"
#include "fm_1697.h"

int fm_1697(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_11_3, bmats.A_16_3, bmats.A_16_4, bmats.A_3_11, bmats.Ax4366, bmats.Ax4559, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_11_1, bmats.B_11_10, bmats.B_11_11, bmats.B_11_12, bmats.B_11_13, bmats.B_11_14, bmats.B_11_15, bmats.B_11_16, bmats.B_11_2, bmats.B_11_3, bmats.B_11_4, bmats.B_11_5, bmats.B_11_6, bmats.B_11_7, bmats.B_11_8, bmats.B_11_9, bmats.B_12_3, bmats.B_14_3, bmats.B_1_3, bmats.B_3_11, bmats.B_5_3, bmats.B_7_3, bmats.B_9_3, bmats.Bx12416, };
    double B_coeffs[24] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_3.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
