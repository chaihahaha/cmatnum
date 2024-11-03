#include "fBx13397.h"
#include "stdafx.h"

inline int fBx13397(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_11_15, bmats.B_16_15, bmats.B_1_15, bmats.B_2_15, bmats.B_3_15, bmats.B_4_15, bmats.B_6_15, bmats.B_8_15, bmats.B_9_15, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13397, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
