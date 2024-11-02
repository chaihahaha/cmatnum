#include "fm_1045.h"

inline int fm_1045(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_15, bmats.A_13_16, bmats.A_8_29, bmats.A_8_30, bmats.Ax3518, bmats.Ax568, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_10_24, bmats.B_11_24, bmats.B_12_24, bmats.B_13_24, bmats.B_14_24, bmats.B_15_24, bmats.B_16_24, bmats.B_1_24, bmats.B_2_24, bmats.B_3_24, bmats.B_4_24, bmats.B_5_24, bmats.B_6_24, bmats.B_7_24, bmats.B_8_13, bmats.B_8_24, bmats.B_9_24, bmats.Bx3057, bmats.Bx4638, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_24.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
