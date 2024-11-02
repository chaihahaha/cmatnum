#include "fm_639.h"

inline int fm_639(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_17, bmats.A_12_18, bmats.A_18_15, bmats.A_18_16, bmats.A_18_27, bmats.A_18_28, bmats.A_28_27, bmats.A_28_28, bmats.Ax2232, bmats.Ax23, bmats.Ax2636, bmats.Ax61, bmats.Ax720, };
    double A_coeffs[13] = {-1, 16, -1, -1, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_28, bmats.B_11_28, bmats.B_12_28, bmats.B_13_28, bmats.B_14_28, bmats.B_15_28, bmats.B_16_28, bmats.B_18_17, bmats.B_18_18, bmats.B_18_19, bmats.B_18_20, bmats.B_18_21, bmats.B_18_22, bmats.B_18_23, bmats.B_18_24, bmats.B_18_25, bmats.B_18_26, bmats.B_18_27, bmats.B_18_28, bmats.B_18_29, bmats.B_18_30, bmats.B_18_31, bmats.B_18_32, bmats.B_1_28, bmats.B_28_2, bmats.B_2_28, bmats.B_3_28, bmats.B_4_28, bmats.B_5_28, bmats.B_6_28, bmats.B_7_28, bmats.B_8_28, bmats.B_9_28, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_28.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
