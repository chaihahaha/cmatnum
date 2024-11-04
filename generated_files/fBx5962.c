#include "stdafx.h"
#include "fBx5962.h"

int fBx5962(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_17_27, bmats.B_18_27, bmats.B_19_27, bmats.B_20_27, bmats.B_21_27, bmats.B_22_27, bmats.B_23_27, bmats.B_24_27, bmats.B_25_27, bmats.B_26_27, bmats.B_31_27, bmats.B_32_27, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx5962, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
