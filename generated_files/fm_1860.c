#include "stdafx.h"
#include "fm_1860.h"

int fm_1860(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_18_10, bmats.A_18_4, bmats.A_26_31, bmats.A_26_32, bmats.Ax4717, bmats.Ax627, };
    double A_coeffs[6] = {-16, 1, -1, -1, -1, -1, };
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_17_2, bmats.B_18_2, bmats.B_18_26, bmats.B_32_2, bmats.Bx12667, bmats.Bx8681, };
    double B_coeffs[6] = {-1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
