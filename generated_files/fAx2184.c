#include "stdafx.h"
#include "fAx2184.h"

int fAx2184(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_16_1, bmats.A_16_10, bmats.A_16_13, bmats.A_16_14, bmats.A_16_15, bmats.A_16_16, bmats.A_16_2, bmats.A_16_3, bmats.A_16_4, bmats.A_16_5, bmats.A_16_6, bmats.A_16_7, bmats.A_16_8, bmats.A_16_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2184, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
