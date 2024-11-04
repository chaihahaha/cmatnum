#include "stdafx.h"
#include "fBx7697.h"

int fBx7697(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_26_23, bmats.B_26_24, bmats.B_26_25, bmats.B_26_26, bmats.B_26_27, bmats.B_26_28, bmats.B_26_29, bmats.B_26_30, bmats.B_26_31, bmats.B_26_32, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7697, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
