#include "fm_15134.h"

inline int fm_15134(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 20;
    double_cmat A_mats[20] = {bmats.A_27_31, bmats.A_27_32, bmats.A_32_1, bmats.A_32_10, bmats.A_32_11, bmats.A_32_12, bmats.A_32_13, bmats.A_32_14, bmats.A_32_15, bmats.A_32_16, bmats.A_32_2, bmats.A_32_3, bmats.A_32_4, bmats.A_32_5, bmats.A_32_6, bmats.A_32_7, bmats.A_32_8, bmats.A_32_9, bmats.Ax609, bmats.Ax7798, };
    double A_coeffs[20] = {-1, -1, 1, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, };
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_31_16, bmats.B_32_16, bmats.B_32_27, bmats.Bx13360, bmats.Bx7429, };
    double B_coeffs[5] = {-1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_16.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
