#include "stdafx.h"
#include "fBx13256.h"

int fBx13256(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_13_4, bmats.B_14_4, bmats.B_15_4, bmats.B_16_4, bmats.B_17_4, bmats.B_18_4, bmats.B_19_4, bmats.B_1_4, bmats.B_20_4, bmats.B_21_4, bmats.B_22_4, bmats.B_23_4, bmats.B_24_4, bmats.B_25_4, bmats.B_26_4, bmats.B_27_4, bmats.B_28_4, bmats.B_29_4, bmats.B_2_4, bmats.B_30_4, bmats.B_31_4, bmats.B_32_4, bmats.B_3_4, bmats.B_5_4, bmats.B_6_4, bmats.B_9_4, bmats.Bx11903, };
    double B_coeffs[27] = {1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13256, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
