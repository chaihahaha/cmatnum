#include "stdafx.h"
#include "fBx13215.h"

int fBx13215(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_30, bmats.B_11_30, bmats.B_12_30, bmats.B_13_30, bmats.B_14_30, bmats.B_15_30, bmats.B_16_30, bmats.B_17_30, bmats.B_18_30, bmats.B_19_30, bmats.B_1_30, bmats.B_20_30, bmats.B_21_30, bmats.B_22_30, bmats.B_23_30, bmats.B_24_30, bmats.B_25_30, bmats.B_26_30, bmats.B_27_30, bmats.B_28_30, bmats.B_29_30, bmats.B_2_30, bmats.B_30_30, bmats.B_31_30, bmats.B_32_30, bmats.B_3_30, bmats.B_4_30, bmats.B_5_30, bmats.B_6_30, bmats.B_7_30, bmats.B_8_30, bmats.B_9_30, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13215, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
