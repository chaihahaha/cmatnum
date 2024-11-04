#include "stdafx.h"
#include "fBx13243.h"

int fBx13243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_14_1, bmats.B_15_1, bmats.B_16_1, bmats.B_17_1, bmats.B_18_1, bmats.B_19_1, bmats.B_20_1, bmats.B_21_1, bmats.B_22_1, bmats.B_23_1, bmats.B_24_1, bmats.B_25_1, bmats.B_26_1, bmats.B_27_1, bmats.B_28_1, bmats.B_29_1, bmats.B_30_1, bmats.B_31_1, bmats.B_32_1, bmats.B_4_1, bmats.B_5_1, bmats.B_6_1, bmats.B_7_1, bmats.Bx12870, };
    double B_coeffs[24] = {1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
