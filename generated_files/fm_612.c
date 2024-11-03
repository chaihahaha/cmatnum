#include "fm_612.h"
#include "stdafx.h"

inline int fm_612(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_17_27, bmats.A_17_28, bmats.A_21_28, bmats.A_28_21, bmats.Ax15, bmats.Ax2508, };
    double A_coeffs[6] = {1, -16, -17, 17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_28, bmats.B_18_28, bmats.B_19_28, bmats.B_20_28, bmats.B_21_17, bmats.B_21_18, bmats.B_21_19, bmats.B_21_20, bmats.B_21_21, bmats.B_21_22, bmats.B_21_23, bmats.B_21_24, bmats.B_21_25, bmats.B_21_26, bmats.B_21_27, bmats.B_21_28, bmats.B_21_29, bmats.B_21_30, bmats.B_21_31, bmats.B_21_32, bmats.B_22_28, bmats.B_23_28, bmats.B_24_28, bmats.B_25_28, bmats.B_26_28, bmats.B_27_28, bmats.B_28_21, bmats.B_28_28, bmats.B_29_28, bmats.B_30_28, bmats.B_31_28, bmats.B_32_28, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_28.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
