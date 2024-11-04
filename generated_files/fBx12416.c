#include "stdafx.h"
#include "fBx12416.h"

int fBx12416(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_10_3, bmats.B_13_3, bmats.B_15_3, bmats.B_16_3, bmats.B_2_3, bmats.B_3_3, bmats.B_4_3, bmats.B_6_3, bmats.B_8_3, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12416, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
