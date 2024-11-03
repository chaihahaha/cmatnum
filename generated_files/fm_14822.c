#include "fm_14822.h"
#include "stdafx.h"

inline int fm_14822(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_11_15, bmats.A_11_16, bmats.A_12_15, bmats.A_15_12, bmats.Ax562, bmats.Ax8488, };
    double A_coeffs[6] = {-16, 1, -17, 17, 1, 1, };
    int n_B_mats = 22;
    double_cmat B_mats[22] = {bmats.B_12_1, bmats.B_12_10, bmats.B_12_11, bmats.B_12_12, bmats.B_12_13, bmats.B_12_14, bmats.B_12_15, bmats.B_12_16, bmats.B_12_2, bmats.B_12_3, bmats.B_12_4, bmats.B_12_5, bmats.B_12_6, bmats.B_12_7, bmats.B_12_8, bmats.B_12_9, bmats.B_14_15, bmats.B_15_12, bmats.B_15_15, bmats.B_4_15, bmats.B_7_15, bmats.Bx13388, };
    double B_coeffs[22] = {-1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_15.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
