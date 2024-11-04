#include "stdafx.h"
#include "fAx3928.h"

int fAx3928(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_5, bmats.A_10_6, bmats.A_11_5, bmats.A_11_6, bmats.A_12_5, bmats.A_12_6, bmats.A_13_5, bmats.A_13_6, bmats.A_16_5, bmats.A_16_6, bmats.A_1_5, bmats.A_1_6, bmats.A_2_5, bmats.A_2_6, bmats.A_3_5, bmats.A_3_6, bmats.A_4_5, bmats.A_4_6, bmats.A_5_5, bmats.A_5_6, bmats.A_6_6, bmats.A_7_5, bmats.A_7_6, bmats.A_8_5, bmats.A_8_6, bmats.A_9_5, bmats.A_9_6, bmats.Ax2086, bmats.Ax2445, bmats.Ax2786, bmats.Ax3074, bmats.Ax3299, bmats.Ax3541, bmats.Ax3828, bmats.Ax3911, bmats.Ax3914, bmats.Ax3917, bmats.Ax3920, bmats.Ax3923, bmats.Ax3926, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3928, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
