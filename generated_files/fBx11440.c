#include "fBx11440.h"
#include "stdafx.h"

inline int fBx11440(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_10_21, bmats.B_11_21, bmats.B_12_21, bmats.B_13_21, bmats.B_14_21, bmats.B_6_21, bmats.B_8_21, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11440, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
