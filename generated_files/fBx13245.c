#include "stdafx.h"
#include "fBx13245.h"

int fBx13245(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_16_17, bmats.B_17_17, bmats.B_18_17, bmats.B_19_17, bmats.B_1_17, bmats.B_20_17, bmats.B_21_17, bmats.B_22_17, bmats.B_23_17, bmats.B_24_17, bmats.B_25_17, bmats.B_26_17, bmats.B_27_17, bmats.B_28_17, bmats.B_29_17, bmats.B_2_17, bmats.B_30_17, bmats.B_31_17, bmats.B_32_17, bmats.Bx12860, };
    double B_coeffs[20] = {-1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13245, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
