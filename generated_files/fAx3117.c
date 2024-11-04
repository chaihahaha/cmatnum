#include "stdafx.h"
#include "fAx3117.h"

int fAx3117(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_10, bmats.A_11_10, bmats.A_11_9, bmats.A_12_10, bmats.A_12_9, bmats.A_13_10, bmats.A_13_9, bmats.A_14_10, bmats.A_14_9, bmats.A_15_10, bmats.A_15_9, bmats.A_16_10, bmats.A_16_9, bmats.A_1_10, bmats.A_1_9, bmats.A_2_10, bmats.A_2_9, bmats.A_5_10, bmats.A_5_9, bmats.A_6_10, bmats.A_6_9, bmats.A_7_10, bmats.A_7_9, bmats.A_8_10, bmats.A_8_9, bmats.A_9_10, bmats.A_9_9, bmats.Ax1189, bmats.Ax2053, bmats.Ax2390, bmats.Ax2677, bmats.Ax2913, bmats.Ax2917, bmats.Ax2920, bmats.Ax2923, bmats.Ax2926, bmats.Ax2929, bmats.Ax2938, bmats.Ax2941, bmats.Ax2944, };
    double A_coeffs[40] = {-17, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3117, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
