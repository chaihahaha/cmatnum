#include "fm_1732.h"
#include "stdafx.h"

inline int fm_1732(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_19_10, bmats.A_19_9, bmats.A_3_3, bmats.A_3_4, bmats.A_4_3, bmats.A_4_4, bmats.A_9_31, bmats.A_9_32, bmats.Ax2825, bmats.Ax4339, bmats.Ax4363, bmats.Ax4482, bmats.Ax769, };
    double A_coeffs[13] = {-1, 16, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 22;
    double_cmat B_mats[22] = {bmats.B_17_3, bmats.B_18_3, bmats.B_19_3, bmats.B_32_3, bmats.B_3_25, bmats.B_9_1, bmats.B_9_10, bmats.B_9_11, bmats.B_9_12, bmats.B_9_13, bmats.B_9_14, bmats.B_9_15, bmats.B_9_16, bmats.B_9_2, bmats.B_9_3, bmats.B_9_4, bmats.B_9_5, bmats.B_9_6, bmats.B_9_7, bmats.B_9_8, bmats.B_9_9, bmats.Bx12263, };
    double B_coeffs[22] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_3.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
