#include "fm_1552.h"

inline int fm_1552(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_19_19, bmats.A_19_20, bmats.A_20_19, bmats.A_20_20, bmats.A_29_15, bmats.A_29_16, bmats.A_4_29, bmats.A_4_30, bmats.Ax176, bmats.Ax435, bmats.Ax4354, bmats.Ax4378, bmats.Ax691, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_15_20, bmats.B_16_20, bmats.B_1_20, bmats.B_20_13, bmats.B_29_27, bmats.B_29_28, bmats.B_29_29, bmats.B_29_30, bmats.B_29_31, bmats.B_29_32, bmats.B_2_20, bmats.B_3_20, bmats.B_4_20, bmats.B_9_20, bmats.Bx11916, bmats.Bx4622, };
    double B_coeffs[16] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
