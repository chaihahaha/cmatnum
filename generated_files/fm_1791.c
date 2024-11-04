#include "stdafx.h"
#include "fm_1791.h"

int fm_1791(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_17, bmats.A_17_18, bmats.A_18_17, bmats.A_18_18, bmats.A_2_29, bmats.A_2_30, bmats.A_30_15, bmats.A_30_16, bmats.Ax158, bmats.Ax429, bmats.Ax4655, bmats.Ax4666, bmats.Ax676, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_16_18, bmats.B_18_14, bmats.B_1_18, bmats.B_2_18, bmats.B_30_22, bmats.Bx12672, bmats.Bx2480, bmats.Bx2481, };
    double B_coeffs[8] = {-1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_18.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
