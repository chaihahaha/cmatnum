#include "fm_1517.h"
#include "stdafx.h"

inline int fm_1517(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_18_21, bmats.A_18_22, bmats.A_21_17, bmats.A_21_23, bmats.Ax3943, bmats.Ax4181, bmats.Ax4292, };
    double A_coeffs[7] = {-16, 1, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_17_21, bmats.B_18_21, bmats.B_19_21, bmats.B_20_21, bmats.B_21_17, bmats.B_21_18, bmats.B_21_19, bmats.B_21_20, bmats.B_21_21, bmats.B_21_22, bmats.B_21_23, bmats.B_21_24, bmats.B_21_25, bmats.B_21_26, bmats.B_21_27, bmats.B_21_28, bmats.B_21_29, bmats.B_21_30, bmats.B_21_31, bmats.B_21_32, bmats.B_22_21, bmats.B_23_21, bmats.B_24_21, bmats.B_25_21, bmats.B_26_21, bmats.B_27_21, bmats.B_28_21, bmats.B_29_21, bmats.B_30_21, bmats.B_31_21, bmats.B_32_21, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_21.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
