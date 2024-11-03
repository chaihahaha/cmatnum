#include "fm_716.h"
#include "stdafx.h"

inline int fm_716(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_11_20, bmats.A_11_25, bmats.A_9_15, bmats.A_9_16, bmats.Ax2757, bmats.Ax579, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 33;
    double_cmat B_mats[33] = {bmats.B_10_27, bmats.B_11_27, bmats.B_11_9, bmats.B_12_27, bmats.B_13_27, bmats.B_14_27, bmats.B_15_27, bmats.B_16_27, bmats.B_1_27, bmats.B_25_1, bmats.B_25_10, bmats.B_25_11, bmats.B_25_12, bmats.B_25_13, bmats.B_25_14, bmats.B_25_15, bmats.B_25_16, bmats.B_25_2, bmats.B_25_3, bmats.B_25_4, bmats.B_25_5, bmats.B_25_6, bmats.B_25_7, bmats.B_25_8, bmats.B_25_9, bmats.B_2_27, bmats.B_3_27, bmats.B_4_27, bmats.B_5_27, bmats.B_6_27, bmats.B_7_27, bmats.B_8_27, bmats.B_9_27, };
    double B_coeffs[33] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
