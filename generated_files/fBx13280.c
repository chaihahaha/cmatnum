#include "fBx13280.h"
#include "stdafx.h"

inline int fBx13280(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_8, bmats.B_11_8, bmats.B_12_8, bmats.B_13_8, bmats.B_14_8, bmats.B_15_8, bmats.B_16_8, bmats.B_17_8, bmats.B_18_8, bmats.B_19_8, bmats.B_1_8, bmats.B_20_8, bmats.B_21_8, bmats.B_22_8, bmats.B_23_8, bmats.B_24_8, bmats.B_25_8, bmats.B_26_8, bmats.B_27_8, bmats.B_28_8, bmats.B_29_8, bmats.B_2_8, bmats.B_30_8, bmats.B_31_8, bmats.B_32_8, bmats.B_3_8, bmats.B_4_8, bmats.B_5_8, bmats.B_6_8, bmats.B_7_8, bmats.B_8_8, bmats.B_9_8, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13280, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
