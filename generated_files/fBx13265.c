#include "fBx13265.h"
#include "stdafx.h"

inline int fBx13265(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_15_21, bmats.B_16_21, bmats.B_17_21, bmats.B_18_21, bmats.B_19_21, bmats.B_1_21, bmats.B_20_21, bmats.B_21_21, bmats.B_22_21, bmats.B_23_21, bmats.B_24_21, bmats.B_25_21, bmats.B_26_21, bmats.B_27_21, bmats.B_28_21, bmats.B_29_21, bmats.B_2_21, bmats.B_30_21, bmats.B_31_21, bmats.B_32_21, bmats.B_3_21, bmats.B_4_21, bmats.B_5_21, bmats.B_7_21, bmats.B_9_21, bmats.Bx11440, };
    double B_coeffs[26] = {-1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13265, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
