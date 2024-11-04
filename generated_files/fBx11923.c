#include "stdafx.h"
#include "fBx11923.h"

int fBx11923(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_21_4, bmats.B_22_4, bmats.B_23_4, bmats.B_24_4, bmats.B_25_4, bmats.B_26_4, bmats.B_27_4, bmats.B_28_4, bmats.B_29_4, bmats.B_30_4, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11923, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
