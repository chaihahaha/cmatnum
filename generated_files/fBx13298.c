#include "fBx13298.h"
#include "stdafx.h"

inline int fBx13298(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_11, bmats.B_11_11, bmats.B_12_11, bmats.B_13_11, bmats.B_14_11, bmats.B_15_11, bmats.B_16_11, bmats.B_17_11, bmats.B_18_11, bmats.B_19_11, bmats.B_1_11, bmats.B_20_11, bmats.B_21_11, bmats.B_22_11, bmats.B_23_11, bmats.B_24_11, bmats.B_25_11, bmats.B_26_11, bmats.B_27_11, bmats.B_28_11, bmats.B_29_11, bmats.B_2_11, bmats.B_30_11, bmats.B_31_11, bmats.B_32_11, bmats.B_3_11, bmats.B_4_11, bmats.B_5_11, bmats.B_6_11, bmats.B_7_11, bmats.B_8_11, bmats.B_9_11, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13298, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
