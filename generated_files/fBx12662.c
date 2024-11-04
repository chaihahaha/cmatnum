#include "stdafx.h"
#include "fBx12662.h"

int fBx12662(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_18_18, bmats.B_19_18, bmats.B_20_18, bmats.B_23_18, bmats.B_24_18, bmats.B_25_18, bmats.B_26_18, bmats.B_27_18, bmats.B_28_18, bmats.B_29_18, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12662, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
