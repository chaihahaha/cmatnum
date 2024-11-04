#include "stdafx.h"
#include "fBx2515.h"

int fBx2515(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_17_13, bmats.B_18_13, bmats.B_19_13, bmats.B_20_13, bmats.B_21_13, bmats.B_22_13, bmats.B_23_13, bmats.B_24_13, bmats.B_25_13, bmats.B_26_13, bmats.B_27_13, bmats.B_28_13, bmats.B_29_13, bmats.B_30_13, bmats.B_31_13, bmats.B_32_13, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2515, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
