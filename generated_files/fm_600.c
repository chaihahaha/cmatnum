#include "fm_600.h"

inline int fm_600(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_12_3, bmats.A_12_4, bmats.A_19_16, bmats.Ax2320, bmats.Ax2489, bmats.Ax962, };
    double A_coeffs[6] = {-16, 1, -1, 1, 1, 1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_12, bmats.B_11_12, bmats.B_12_12, bmats.B_13_12, bmats.B_14_12, bmats.B_15_12, bmats.B_16_12, bmats.B_1_12, bmats.B_28_3, bmats.B_2_12, bmats.B_3_12, bmats.B_3_17, bmats.B_3_18, bmats.B_3_19, bmats.B_3_20, bmats.B_3_21, bmats.B_3_22, bmats.B_3_23, bmats.B_3_24, bmats.B_3_25, bmats.B_3_26, bmats.B_3_27, bmats.B_3_28, bmats.B_3_29, bmats.B_3_30, bmats.B_3_31, bmats.B_3_32, bmats.B_4_12, bmats.B_5_12, bmats.B_6_12, bmats.B_7_12, bmats.B_8_12, bmats.B_9_12, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_12.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
