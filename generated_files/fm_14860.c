#include "fm_14860.h"
#include "stdafx.h"

inline int fm_14860(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_15_17, bmats.A_15_18, bmats.A_15_19, bmats.A_15_20, bmats.A_15_21, bmats.A_15_22, bmats.A_15_23, bmats.A_15_24, bmats.A_15_25, bmats.A_15_26, bmats.A_15_27, bmats.A_15_28, bmats.A_15_29, bmats.A_15_30, bmats.A_15_31, bmats.A_15_32, bmats.A_16_15, bmats.A_16_16, bmats.Ax463, bmats.Ax722, };
    double A_coeffs[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -16, -1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_14_31, bmats.B_15_16, bmats.B_32_1, bmats.B_32_10, bmats.B_32_11, bmats.B_32_12, bmats.B_32_13, bmats.B_32_14, bmats.B_32_15, bmats.B_32_16, bmats.B_32_2, bmats.B_32_3, bmats.B_32_4, bmats.B_32_5, bmats.B_32_6, bmats.B_32_7, bmats.B_32_8, bmats.B_32_9, bmats.Bx13226, };
    double B_coeffs[19] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
