#include "fBx13226.h"
#include "stdafx.h"

inline int fBx13226(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_10_31, bmats.B_11_31, bmats.B_12_31, bmats.B_13_31, bmats.B_15_31, bmats.B_16_31, bmats.B_1_31, bmats.B_2_31, bmats.B_3_31, bmats.B_4_31, bmats.B_5_31, bmats.B_6_31, bmats.B_7_31, bmats.B_8_31, bmats.B_9_31, };
    double B_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13226, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
