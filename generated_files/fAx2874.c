#include "stdafx.h"
#include "fAx2874.h"

int fAx2874(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_25, bmats.A_10_26, bmats.A_11_25, bmats.A_11_26, bmats.A_12_25, bmats.A_12_26, bmats.A_13_25, bmats.A_13_26, bmats.A_14_25, bmats.A_14_26, bmats.A_15_25, bmats.A_15_26, bmats.A_16_25, bmats.A_16_26, bmats.A_1_25, bmats.A_1_26, bmats.A_2_25, bmats.A_2_26, bmats.A_3_25, bmats.A_3_26, bmats.A_4_25, bmats.A_4_26, bmats.A_5_25, bmats.A_5_26, bmats.A_6_25, bmats.A_6_26, bmats.A_7_25, bmats.A_7_26, bmats.A_8_25, bmats.A_8_26, bmats.A_9_25, bmats.A_9_26, bmats.Ax1489, bmats.Ax2047, bmats.Ax2387, bmats.Ax2674, bmats.Ax2839, bmats.Ax2842, bmats.Ax2845, bmats.Ax2848, bmats.Ax2851, bmats.Ax2854, bmats.Ax2857, bmats.Ax2860, bmats.Ax2863, bmats.Ax2866, bmats.Ax2869, bmats.Ax2872, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2874, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
