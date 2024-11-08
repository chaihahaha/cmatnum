#include "stdafx.h"
#include "fBx13360.h"

int fBx13360(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_17_16, bmats.B_18_16, bmats.B_19_16, bmats.B_20_16, bmats.B_21_16, bmats.B_22_16, bmats.B_23_16, bmats.B_24_16, bmats.B_25_16, bmats.B_26_16, bmats.B_27_16, bmats.B_28_16, bmats.B_29_16, bmats.B_30_16, };
    double B_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13360, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
