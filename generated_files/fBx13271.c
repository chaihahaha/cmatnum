#include "stdafx.h"
#include "fBx13271.h"

int fBx13271(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_11_22, bmats.B_14_22, bmats.B_15_22, bmats.B_16_22, bmats.B_17_22, bmats.B_18_22, bmats.B_19_22, bmats.B_1_22, bmats.B_20_22, bmats.B_21_22, bmats.B_22_22, bmats.B_23_22, bmats.B_24_22, bmats.B_25_22, bmats.B_26_22, bmats.B_27_22, bmats.B_28_22, bmats.B_29_22, bmats.B_2_22, bmats.B_30_22, bmats.B_31_22, bmats.B_32_22, bmats.B_3_22, bmats.B_4_22, bmats.B_5_22, bmats.B_6_22, bmats.Bx10907, };
    double B_coeffs[27] = {-1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Bx13271, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
