#include "stdafx.h"
#include "fBx5970.h"

int fBx5970(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_17_11, bmats.B_18_11, bmats.B_19_11, bmats.B_20_11, bmats.B_21_11, bmats.B_22_11, bmats.B_23_11, bmats.B_24_11, bmats.B_25_11, bmats.B_26_11, bmats.B_27_11, bmats.B_28_11, bmats.B_29_11, bmats.B_30_11, bmats.B_31_11, bmats.B_32_11, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx5970, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
