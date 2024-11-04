#include "stdafx.h"
#include "fBx12263.h"

int fBx12263(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_20_3, bmats.B_21_3, bmats.B_22_3, bmats.B_23_3, bmats.B_24_3, bmats.B_25_3, bmats.B_26_3, bmats.B_27_3, bmats.B_28_3, bmats.B_29_3, bmats.B_30_3, bmats.B_31_3, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12263, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
