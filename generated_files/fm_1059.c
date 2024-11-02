#include "fm_1059.h"

inline int fm_1059(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_18_23, bmats.A_18_24, bmats.A_24_23, bmats.A_24_24, bmats.A_25_15, bmats.A_25_16, bmats.A_8_25, bmats.A_8_26, bmats.Ax115, bmats.Ax2845, bmats.Ax3386, bmats.Ax340, bmats.Ax700, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_10_24, bmats.B_11_24, bmats.B_12_24, bmats.B_13_24, bmats.B_14_24, bmats.B_15_24, bmats.B_16_24, bmats.B_1_24, bmats.B_24_9, bmats.B_25_17, bmats.B_25_21, bmats.B_25_25, bmats.B_25_27, bmats.B_25_28, bmats.B_25_29, bmats.B_25_30, bmats.B_2_24, bmats.B_3_24, bmats.B_4_24, bmats.B_5_24, bmats.B_6_24, bmats.B_7_24, bmats.B_8_24, bmats.B_9_24, bmats.Bx9522, };
    double B_coeffs[25] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_24.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
