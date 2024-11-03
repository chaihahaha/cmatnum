#include "fm_14814.h"
#include "stdafx.h"

inline int fm_14814(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_11_15, bmats.A_12_15, bmats.A_12_16, bmats.A_15_11, bmats.Ax565, bmats.Ax8488, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_11_1, bmats.B_11_10, bmats.B_11_11, bmats.B_11_12, bmats.B_11_13, bmats.B_11_14, bmats.B_11_15, bmats.B_11_16, bmats.B_11_2, bmats.B_11_3, bmats.B_11_4, bmats.B_11_5, bmats.B_11_6, bmats.B_11_7, bmats.B_11_8, bmats.B_11_9, bmats.B_15_11, bmats.B_8_15, bmats.B_9_15, bmats.Bx13218, };
    double B_coeffs[20] = {-1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_15.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
