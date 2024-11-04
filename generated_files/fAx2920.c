#include "stdafx.h"
#include "fAx2920.h"

int fAx2920(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_8_1, bmats.A_8_11, bmats.A_8_12, bmats.A_8_13, bmats.A_8_14, bmats.A_8_15, bmats.A_8_16, bmats.A_8_2, bmats.A_8_3, bmats.A_8_4, bmats.A_8_5, bmats.A_8_6, bmats.A_8_7, bmats.A_8_8, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2920, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
