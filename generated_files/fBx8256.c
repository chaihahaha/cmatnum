#include "stdafx.h"
#include "fBx8256.h"

int fBx8256(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_20_25, bmats.B_21_25, bmats.B_22_25, bmats.B_23_25, bmats.B_24_25, bmats.B_31_25, bmats.B_32_25, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx8256, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
