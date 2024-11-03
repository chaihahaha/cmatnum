#include "fBx13388.h"
#include "stdafx.h"

inline int fBx13388(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_10_15, bmats.B_11_15, bmats.B_13_15, bmats.B_16_15, bmats.B_1_15, bmats.B_2_15, bmats.B_3_15, bmats.B_5_15, bmats.B_6_15, bmats.B_8_15, bmats.B_9_15, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13388, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
