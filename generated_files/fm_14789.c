#include "fm_14789.h"
#include "stdafx.h"

inline int fm_14789(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_23_31, bmats.A_23_32, bmats.A_31_6, bmats.A_31_7, bmats.Ax618, bmats.Ax8479, };
    double A_coeffs[6] = {-1, -1, 1, -16, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_31_23, bmats.Bx11069, bmats.Bx13385, };
    double B_coeffs[3] = {1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_15.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
