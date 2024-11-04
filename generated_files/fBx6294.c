#include "stdafx.h"
#include "fBx6294.h"

int fBx6294(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_28_1, bmats.B_28_10, bmats.B_28_11, bmats.B_28_2, bmats.B_28_3, bmats.B_28_4, bmats.B_28_5, bmats.B_28_6, bmats.B_28_7, bmats.B_28_8, bmats.B_28_9, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx6294, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
