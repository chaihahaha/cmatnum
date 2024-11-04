#include "stdafx.h"
#include "fBx13277.h"

int fBx13277(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_12_23, bmats.B_13_23, bmats.B_15_23, bmats.B_16_23, bmats.B_17_23, bmats.B_18_23, bmats.B_19_23, bmats.B_1_23, bmats.B_20_23, bmats.B_21_23, bmats.B_22_23, bmats.B_23_23, bmats.B_24_23, bmats.B_25_23, bmats.B_26_23, bmats.B_27_23, bmats.B_28_23, bmats.B_29_23, bmats.B_2_23, bmats.B_30_23, bmats.B_31_23, bmats.B_32_23, bmats.B_3_23, bmats.B_4_23, bmats.B_5_23, bmats.B_6_23, bmats.Bx10243, };
    double B_coeffs[27] = {-1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13277, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
