#include "fm_14864.h"

inline int fm_14864(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_15, bmats.A_12_16, bmats.A_16_15, bmats.A_16_16, bmats.A_1_31, bmats.A_1_32, bmats.A_32_1, bmats.A_32_2, bmats.Ax463, bmats.Ax4670, bmats.Ax565, bmats.Ax645, bmats.Ax7791, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_16_17, bmats.B_1_1, bmats.B_1_10, bmats.B_1_11, bmats.B_1_12, bmats.B_1_13, bmats.B_1_14, bmats.B_1_15, bmats.B_1_16, bmats.B_1_2, bmats.B_1_3, bmats.B_1_4, bmats.B_1_5, bmats.B_1_6, bmats.B_1_7, bmats.B_1_8, bmats.B_1_9, bmats.B_31_16, bmats.B_32_16, bmats.Bx13360, };
    double B_coeffs[20] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_16.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
