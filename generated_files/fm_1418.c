#include "fm_1418.h"
#include "stdafx.h"

inline int fm_1418(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_17_22, bmats.A_22_17, bmats.A_22_22, bmats.Ax3960, };
    double A_coeffs[4] = {-17, 17, -17, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_17, bmats.B_17_18, bmats.B_17_19, bmats.B_17_20, bmats.B_17_21, bmats.B_17_22, bmats.B_17_23, bmats.B_17_24, bmats.B_17_25, bmats.B_17_26, bmats.B_17_27, bmats.B_17_28, bmats.B_17_29, bmats.B_17_30, bmats.B_17_31, bmats.B_17_32, bmats.B_18_22, bmats.B_19_22, bmats.B_20_22, bmats.B_21_22, bmats.B_22_17, bmats.B_23_22, bmats.B_30_22, bmats.B_31_22, bmats.B_32_22, bmats.Bx10896, };
    double B_coeffs[26] = {-1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_22.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
