#include "stdafx.h"
#include "fBx12682.h"

int fBx12682(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_15_10, bmats.B_15_14, bmats.B_15_15, bmats.B_15_16, bmats.B_15_3, bmats.B_15_4, bmats.B_15_5, bmats.B_15_6, bmats.B_15_7, bmats.B_15_8, bmats.B_15_9, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12682, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
