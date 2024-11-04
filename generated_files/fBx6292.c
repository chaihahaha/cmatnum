#include "stdafx.h"
#include "fBx6292.h"

int fBx6292(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_28_17, bmats.B_28_19, bmats.B_28_20, bmats.B_28_21, bmats.B_28_22, bmats.B_28_24, bmats.B_28_27, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx6292, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
