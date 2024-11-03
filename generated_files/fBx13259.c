#include "fBx13259.h"
#include "stdafx.h"

inline int fBx13259(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_15_20, bmats.B_16_20, bmats.B_17_20, bmats.B_18_20, bmats.B_19_20, bmats.B_1_20, bmats.B_20_20, bmats.B_21_20, bmats.B_22_20, bmats.B_23_20, bmats.B_24_20, bmats.B_25_20, bmats.B_26_20, bmats.B_27_20, bmats.B_28_20, bmats.B_29_20, bmats.B_2_20, bmats.B_30_20, bmats.B_31_20, bmats.B_32_20, bmats.B_3_20, bmats.B_4_20, bmats.B_9_20, bmats.Bx11916, };
    double B_coeffs[24] = {-1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13259, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
