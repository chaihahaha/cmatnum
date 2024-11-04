#include "stdafx.h"
#include "fBx13251.h"

int fBx13251(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_11_3, bmats.B_12_3, bmats.B_14_3, bmats.B_17_3, bmats.B_18_3, bmats.B_19_3, bmats.B_1_3, bmats.B_20_3, bmats.B_21_3, bmats.B_22_3, bmats.B_23_3, bmats.B_24_3, bmats.B_25_3, bmats.B_26_3, bmats.B_27_3, bmats.B_28_3, bmats.B_29_3, bmats.B_30_3, bmats.B_31_3, bmats.B_32_3, bmats.B_5_3, bmats.B_7_3, bmats.B_9_3, bmats.Bx12416, };
    double B_coeffs[24] = {1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13251, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
