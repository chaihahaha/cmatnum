#include "stdafx.h"
#include "fBx7193.h"

int fBx7193(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_17_10, bmats.B_18_10, bmats.B_19_10, bmats.B_20_10, bmats.B_21_10, bmats.B_22_10, bmats.B_23_10, bmats.B_24_10, bmats.B_25_10, bmats.B_26_10, bmats.B_27_10, bmats.B_28_10, bmats.B_29_10, bmats.B_30_10, bmats.B_31_10, bmats.B_32_10, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7193, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
