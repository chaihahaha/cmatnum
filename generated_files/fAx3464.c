#include "stdafx.h"
#include "fAx3464.h"

int fAx3464(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_4_1, bmats.A_4_10, bmats.A_4_11, bmats.A_4_12, bmats.A_4_13, bmats.A_4_14, bmats.A_4_15, bmats.A_4_16, bmats.A_4_2, bmats.A_4_3, bmats.A_4_4, bmats.A_4_5, bmats.A_4_6, bmats.A_4_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3464, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
