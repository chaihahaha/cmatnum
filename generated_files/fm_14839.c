#include "fm_14839.h"
#include "stdafx.h"

inline int fm_14839(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_29_31, bmats.A_29_32, bmats.A_30_31, bmats.A_31_30, bmats.Ax615, bmats.Ax8493, };
    double A_coeffs[6] = {-16, 1, -17, 17, 1, 1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_18_31, bmats.B_19_31, bmats.B_20_31, bmats.B_21_31, bmats.B_22_31, bmats.B_23_31, bmats.B_24_31, bmats.B_30_18, bmats.B_30_19, bmats.B_30_20, bmats.B_30_21, bmats.B_30_22, bmats.B_30_23, bmats.B_30_24, bmats.B_30_31, bmats.B_31_30, bmats.B_31_31, bmats.Bx13390, bmats.Bx2480, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
