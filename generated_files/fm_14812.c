#include "stdafx.h"
#include "fm_14812.h"

int fm_14812(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_15, bmats.A_10_16, bmats.A_15_26, bmats.A_15_27, bmats.Ax582, bmats.Ax8486, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_14_31, bmats.B_15_10, bmats.B_26_10, bmats.B_26_11, bmats.B_26_12, bmats.B_26_13, bmats.B_26_14, bmats.B_26_15, bmats.B_26_16, bmats.B_26_8, bmats.B_26_9, bmats.Bx13226, bmats.Bx8679, };
    double B_coeffs[13] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
