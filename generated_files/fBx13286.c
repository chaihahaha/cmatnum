#include "stdafx.h"
#include "fBx13286.h"

int fBx13286(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_9, bmats.B_11_9, bmats.B_12_9, bmats.B_13_9, bmats.B_14_9, bmats.B_15_9, bmats.B_16_9, bmats.B_17_9, bmats.B_18_9, bmats.B_19_9, bmats.B_1_9, bmats.B_20_9, bmats.B_21_9, bmats.B_22_9, bmats.B_23_9, bmats.B_24_9, bmats.B_25_9, bmats.B_26_9, bmats.B_27_9, bmats.B_28_9, bmats.B_29_9, bmats.B_2_9, bmats.B_30_9, bmats.B_31_9, bmats.B_32_9, bmats.B_3_9, bmats.B_4_9, bmats.B_5_9, bmats.B_6_9, bmats.B_7_9, bmats.B_8_9, bmats.B_9_9, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13286, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
