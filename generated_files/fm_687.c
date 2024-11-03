#include "fm_687.h"
#include "stdafx.h"

inline int fm_687(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_11_11, bmats.A_11_12, bmats.A_12_31, bmats.A_12_32, bmats.A_27_11, bmats.A_27_12, bmats.A_3_11, bmats.A_3_12, bmats.Ax2190, bmats.Ax2208, bmats.Ax2248, bmats.Ax2558, bmats.Ax757, };
    double A_coeffs[13] = {16, -1, -1, -1, -1, 16, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_11_28, bmats.B_12_12, bmats.B_12_14, bmats.B_12_5, bmats.B_12_7, bmats.B_12_9, bmats.Bx5970, bmats.Bx6289, };
    double B_coeffs[8] = {1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_11.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
