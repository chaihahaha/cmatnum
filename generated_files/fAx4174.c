#include "stdafx.h"
#include "fAx4174.h"

int fAx4174(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 42;
    double_cmat A_mats[42] = {bmats.A_10_5, bmats.A_10_6, bmats.A_11_5, bmats.A_11_6, bmats.A_12_5, bmats.A_12_6, bmats.A_13_5, bmats.A_13_6, bmats.A_14_5, bmats.A_14_6, bmats.A_15_5, bmats.A_15_6, bmats.A_16_5, bmats.A_16_6, bmats.A_1_5, bmats.A_1_6, bmats.A_3_5, bmats.A_3_6, bmats.A_4_5, bmats.A_4_6, bmats.A_6_5, bmats.A_6_6, bmats.A_7_5, bmats.A_7_6, bmats.A_8_5, bmats.A_8_6, bmats.A_9_5, bmats.A_9_6, bmats.Ax1656, bmats.Ax2086, bmats.Ax2445, bmats.Ax2786, bmats.Ax3074, bmats.Ax3299, bmats.Ax3541, bmats.Ax3828, bmats.Ax3907, bmats.Ax3911, bmats.Ax3917, bmats.Ax3923, bmats.Ax3926, bmats.Ax3953, };
    double A_coeffs[42] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4174, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
