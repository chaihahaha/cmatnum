#include "stdafx.h"
#include "fBx10249.h"

int fBx10249(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_10_7, bmats.B_12_7, bmats.B_2_7, bmats.B_7_7, bmats.B_8_7, bmats.B_9_7, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10249, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
