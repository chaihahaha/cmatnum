#include "stdafx.h"
#include "fBx8279.h"

int fBx8279(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_25, bmats.B_11_25, bmats.B_12_25, bmats.B_13_25, bmats.B_14_25, bmats.B_15_25, bmats.B_16_25, bmats.B_1_25, bmats.B_2_25, bmats.B_3_25, bmats.B_4_25, bmats.B_5_25, bmats.B_6_25, bmats.B_7_25, bmats.B_8_25, bmats.B_9_25, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx8279, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
