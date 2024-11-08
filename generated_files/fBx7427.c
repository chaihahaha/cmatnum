#include "stdafx.h"
#include "fBx7427.h"

int fBx7427(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_27_1, bmats.B_27_2, bmats.B_27_3, bmats.B_27_4, bmats.B_27_5, bmats.B_27_6, bmats.B_27_7, bmats.B_27_8, bmats.B_27_9, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7427, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
