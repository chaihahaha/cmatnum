#include "stdafx.h"
#include "fBx13209.h"

int fBx13209(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_17_29, bmats.B_18_29, bmats.B_19_29, bmats.B_20_29, bmats.B_21_29, bmats.B_22_29, bmats.B_23_29, bmats.B_24_29, bmats.B_25_29, bmats.B_26_29, bmats.B_27_29, bmats.B_28_29, bmats.B_29_29, bmats.B_30_29, bmats.B_31_29, bmats.B_32_29, bmats.Bx2488, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13209, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
