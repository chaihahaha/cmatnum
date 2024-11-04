#include "stdafx.h"
#include "fBx13292.h"

int fBx13292(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_10, bmats.B_11_10, bmats.B_12_10, bmats.B_13_10, bmats.B_14_10, bmats.B_15_10, bmats.B_16_10, bmats.B_17_10, bmats.B_18_10, bmats.B_19_10, bmats.B_1_10, bmats.B_20_10, bmats.B_21_10, bmats.B_22_10, bmats.B_23_10, bmats.B_24_10, bmats.B_25_10, bmats.B_26_10, bmats.B_27_10, bmats.B_28_10, bmats.B_29_10, bmats.B_2_10, bmats.B_30_10, bmats.B_31_10, bmats.B_32_10, bmats.B_3_10, bmats.B_4_10, bmats.B_5_10, bmats.B_6_10, bmats.B_7_10, bmats.B_8_10, bmats.B_9_10, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13292, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
