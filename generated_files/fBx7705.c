#include "stdafx.h"
#include "fBx7705.h"

int fBx7705(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_26_10, bmats.B_26_11, bmats.B_26_12, bmats.B_26_13, bmats.B_26_14, bmats.B_26_15, bmats.B_26_16, bmats.B_26_8, bmats.B_26_9, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7705, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
