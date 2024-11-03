#include "fBx13283.h"
#include "stdafx.h"

inline int fBx13283(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_24, bmats.B_11_24, bmats.B_12_24, bmats.B_13_24, bmats.B_14_24, bmats.B_15_24, bmats.B_16_24, bmats.B_17_24, bmats.B_18_24, bmats.B_19_24, bmats.B_1_24, bmats.B_20_24, bmats.B_21_24, bmats.B_22_24, bmats.B_23_24, bmats.B_24_24, bmats.B_25_24, bmats.B_26_24, bmats.B_27_24, bmats.B_28_24, bmats.B_29_24, bmats.B_2_24, bmats.B_30_24, bmats.B_31_24, bmats.B_32_24, bmats.B_3_24, bmats.B_4_24, bmats.B_5_24, bmats.B_6_24, bmats.B_7_24, bmats.B_8_24, bmats.B_9_24, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13283, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
