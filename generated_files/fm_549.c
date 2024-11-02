#include "fm_549.h"

inline int fm_549(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_25, bmats.A_12_26, bmats.A_18_27, bmats.A_18_28, bmats.A_25_15, bmats.A_25_16, bmats.A_28_27, bmats.A_28_28, bmats.Ax2232, bmats.Ax23, bmats.Ax2387, bmats.Ax61, bmats.Ax700, };
    double A_coeffs[13] = {16, -1, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_28, bmats.B_11_28, bmats.B_12_28, bmats.B_13_28, bmats.B_14_28, bmats.B_15_28, bmats.B_16_28, bmats.B_1_28, bmats.B_25_17, bmats.B_25_18, bmats.B_25_19, bmats.B_25_20, bmats.B_25_21, bmats.B_25_22, bmats.B_25_23, bmats.B_25_24, bmats.B_25_25, bmats.B_25_26, bmats.B_25_27, bmats.B_25_28, bmats.B_25_29, bmats.B_25_30, bmats.B_25_31, bmats.B_25_32, bmats.B_28_9, bmats.B_2_28, bmats.B_3_28, bmats.B_4_28, bmats.B_5_28, bmats.B_6_28, bmats.B_7_28, bmats.B_8_28, bmats.B_9_28, };
    double B_coeffs[33] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_28.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
