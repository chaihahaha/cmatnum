#include "fm_14873.h"
#include "stdafx.h"

inline int fm_14873(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_16_17, bmats.A_16_18, bmats.A_18_15, bmats.A_18_16, bmats.A_28_31, bmats.A_28_32, bmats.A_32_31, bmats.A_32_32, bmats.Ax4680, bmats.Ax533, bmats.Ax612, bmats.Ax720, bmats.Ax7795, };
    double A_coeffs[13] = {-1, 16, -1, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_15_32, bmats.B_16_32, bmats.B_18_17, bmats.B_18_18, bmats.B_18_19, bmats.B_18_20, bmats.B_18_21, bmats.B_18_22, bmats.B_18_23, bmats.B_18_24, bmats.B_18_25, bmats.B_18_26, bmats.B_18_27, bmats.B_18_28, bmats.B_18_29, bmats.B_18_30, bmats.B_18_31, bmats.B_18_32, bmats.B_32_2, bmats.Bx13238, };
    double B_coeffs[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
