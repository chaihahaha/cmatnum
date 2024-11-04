#include "stdafx.h"
#include "fBx7712.h"

int fBx7712(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_10_17, bmats.B_10_24, bmats.B_10_25, bmats.B_10_26, bmats.B_10_27, bmats.B_10_28, bmats.B_10_29, bmats.B_10_30, bmats.B_10_31, bmats.B_10_32, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7712, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
