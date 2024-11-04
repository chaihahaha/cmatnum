#include "stdafx.h"
#include "fBx4625.h"

int fBx4625(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_17_28, bmats.B_18_28, bmats.B_19_28, bmats.B_20_28, bmats.B_21_28, bmats.B_22_28, bmats.B_23_28, bmats.B_24_28, bmats.B_25_28, bmats.B_26_28, bmats.B_27_28, bmats.B_31_28, bmats.B_32_28, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4625, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
