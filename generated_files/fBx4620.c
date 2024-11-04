#include "stdafx.h"
#include "fBx4620.h"

int fBx4620(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_10_12, bmats.B_15_12, bmats.B_16_12, bmats.B_3_12, bmats.B_4_12, bmats.B_6_12, bmats.B_7_12, bmats.B_8_12, bmats.B_9_12, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4620, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
