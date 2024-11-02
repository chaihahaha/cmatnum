#include "fm_1806.h"

inline int fm_1806(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_16_31, bmats.A_16_32, bmats.A_18_15, bmats.A_18_16, bmats.A_1_1, bmats.A_1_2, bmats.A_2_1, bmats.A_2_2, bmats.Ax4647, bmats.Ax4659, bmats.Ax4661, bmats.Ax720, bmats.Ax751, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_16_1, bmats.B_16_10, bmats.B_16_11, bmats.B_16_12, bmats.B_16_13, bmats.B_16_14, bmats.B_16_15, bmats.B_16_16, bmats.B_16_2, bmats.B_16_3, bmats.B_16_4, bmats.B_16_5, bmats.B_16_6, bmats.B_16_7, bmats.B_16_8, bmats.B_16_9, bmats.B_17_2, bmats.B_18_2, bmats.B_2_32, bmats.B_32_2, bmats.Bx12667, };
    double B_coeffs[21] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_2.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
