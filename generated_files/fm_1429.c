#include "fm_1429.h"
#include "stdafx.h"

inline int fm_1429(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_18_21, bmats.A_18_22, bmats.A_21_21, bmats.A_21_22, bmats.A_28_15, bmats.A_28_16, bmats.A_5_27, bmats.A_5_28, bmats.Ax2297, bmats.Ax3937, bmats.Ax3943, bmats.Ax4181, bmats.Ax688, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_15_21, bmats.B_16_21, bmats.B_1_21, bmats.B_21_12, bmats.B_28_18, bmats.B_28_23, bmats.B_28_25, bmats.B_28_26, bmats.B_28_28, bmats.B_28_29, bmats.B_28_30, bmats.B_28_31, bmats.B_28_32, bmats.B_2_21, bmats.B_3_21, bmats.B_4_21, bmats.B_5_21, bmats.B_7_21, bmats.B_9_21, bmats.Bx11440, bmats.Bx6292, };
    double B_coeffs[21] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_21.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
