#include "fm_397.h"

inline int fm_397(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.A_14_1, bmats.A_14_14, bmats.A_1_14, bmats.Ax1056, };
    double A_coeffs[4] = {17, -17, -17, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_14, bmats.B_11_14, bmats.B_12_14, bmats.B_13_14, bmats.B_14_1, bmats.B_14_14, bmats.B_15_14, bmats.B_16_14, bmats.B_1_1, bmats.B_1_10, bmats.B_1_11, bmats.B_1_12, bmats.B_1_13, bmats.B_1_14, bmats.B_1_15, bmats.B_1_16, bmats.B_1_2, bmats.B_1_3, bmats.B_1_4, bmats.B_1_5, bmats.B_1_6, bmats.B_1_7, bmats.B_1_8, bmats.B_1_9, bmats.B_2_14, bmats.B_3_14, bmats.B_4_14, bmats.B_5_14, bmats.B_6_14, bmats.B_7_14, bmats.B_8_14, bmats.B_9_14, };
    double B_coeffs[32] = {-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_14.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
