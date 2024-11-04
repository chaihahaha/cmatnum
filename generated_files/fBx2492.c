#include "stdafx.h"
#include "fBx2492.h"

int fBx2492(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_20_29, bmats.B_21_29, bmats.B_22_29, bmats.B_23_29, bmats.B_24_29, bmats.B_25_29, bmats.B_26_29, bmats.B_32_29, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2492, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
