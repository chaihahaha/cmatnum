#include "stdafx.h"
#include "fBx11061.h"

int fBx11061(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_17_22, bmats.B_18_22, bmats.B_19_22, bmats.B_20_22, bmats.B_21_22, bmats.B_22_22, bmats.B_23_22, bmats.B_26_22, bmats.B_27_22, bmats.B_30_22, bmats.B_31_22, bmats.B_32_22, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11061, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
