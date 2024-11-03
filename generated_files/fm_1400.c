#include "fm_1400.h"
#include "stdafx.h"

inline int fm_1400(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_21_14, bmats.A_30_31, bmats.A_30_32, bmats.Ax1674, bmats.Ax4126, bmats.Ax604, };
    double A_coeffs[6] = {-16, -1, -1, -1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_14_17, bmats.B_17_5, bmats.B_18_5, bmats.B_19_5, bmats.B_20_5, bmats.B_21_30, bmats.B_21_5, bmats.B_28_5, bmats.B_30_5, bmats.B_31_5, bmats.B_32_5, bmats.Bx11450, bmats.Bx2496, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_5.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
