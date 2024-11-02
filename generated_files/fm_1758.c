#include "fm_1758.h"

inline int fm_1758(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_19_21, bmats.A_19_22, bmats.A_6_30, bmats.Ax1710, bmats.Ax3946, bmats.Ax4508, };
    double A_coeffs[6] = {1, -16, -1, 1, 1, 1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_17_19, bmats.B_18_19, bmats.B_20_19, bmats.B_22_1, bmats.B_22_10, bmats.B_22_11, bmats.B_22_12, bmats.B_22_13, bmats.B_22_14, bmats.B_22_15, bmats.B_22_16, bmats.B_22_2, bmats.B_22_3, bmats.B_22_4, bmats.B_22_5, bmats.B_22_6, bmats.B_22_7, bmats.B_22_8, bmats.B_22_9, bmats.B_23_19, bmats.B_24_19, bmats.B_26_19, bmats.B_27_19, bmats.B_30_19, bmats.B_32_19, bmats.B_3_22, bmats.Bx12409, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_19.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
