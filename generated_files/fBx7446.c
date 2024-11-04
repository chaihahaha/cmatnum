#include "stdafx.h"
#include "fBx7446.h"

int fBx7446(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_29_17, bmats.B_29_18, bmats.B_29_19, bmats.B_29_20, bmats.B_29_21, bmats.B_29_22, bmats.B_29_23, bmats.B_29_27, bmats.B_29_28, bmats.B_29_29, bmats.B_29_30, bmats.B_29_31, bmats.B_29_32, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7446, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
