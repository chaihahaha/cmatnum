#include "stdafx.h"
#include "fBx12989.h"

int fBx12989(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_10_17, bmats.B_11_17, bmats.B_12_17, bmats.B_13_17, bmats.B_14_17, bmats.B_15_17, bmats.B_16_17, bmats.B_1_17, bmats.B_2_17, bmats.B_3_17, bmats.B_7_17, bmats.B_8_17, bmats.B_9_17, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12989, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
