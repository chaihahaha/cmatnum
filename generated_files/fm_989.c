#include "fm_989.h"
#include "stdafx.h"

inline int fm_989(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_18_31, bmats.A_18_32, bmats.A_25_2, bmats.A_25_7, bmats.Ax3330, bmats.Ax600, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_17_9, bmats.B_18_9, bmats.B_19_9, bmats.B_20_9, bmats.B_21_9, bmats.B_22_9, bmats.B_23_9, bmats.B_24_9, bmats.B_25_18, bmats.B_25_9, bmats.B_26_9, bmats.B_27_9, bmats.B_28_9, bmats.B_29_9, bmats.B_2_17, bmats.B_2_18, bmats.B_2_19, bmats.B_2_20, bmats.B_2_21, bmats.B_2_22, bmats.B_2_23, bmats.B_2_24, bmats.B_2_25, bmats.B_2_26, bmats.B_2_27, bmats.B_2_28, bmats.B_2_29, bmats.B_2_30, bmats.B_2_31, bmats.B_2_32, bmats.B_30_9, bmats.B_31_9, bmats.B_32_9, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_9.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
