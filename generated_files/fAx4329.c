#include "stdafx.h"
#include "fAx4329.h"

int fAx4329(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_19, bmats.A_10_20, bmats.A_11_19, bmats.A_11_20, bmats.A_12_19, bmats.A_12_20, bmats.A_13_19, bmats.A_13_20, bmats.A_14_19, bmats.A_14_20, bmats.A_15_19, bmats.A_15_20, bmats.A_16_19, bmats.A_16_20, bmats.A_1_19, bmats.A_1_20, bmats.A_2_19, bmats.A_2_20, bmats.A_3_19, bmats.A_3_20, bmats.A_4_19, bmats.A_4_20, bmats.A_5_19, bmats.A_5_20, bmats.A_6_19, bmats.A_6_20, bmats.A_7_19, bmats.A_7_20, bmats.A_8_19, bmats.A_8_20, bmats.A_9_19, bmats.A_9_20, bmats.Ax1784, bmats.Ax2146, bmats.Ax2486, bmats.Ax2768, bmats.Ax3125, bmats.Ax3354, bmats.Ax3598, bmats.Ax3810, bmats.Ax4099, bmats.Ax4239, bmats.Ax4313, bmats.Ax4318, bmats.Ax4321, bmats.Ax4324, bmats.Ax4327, bmats.Ax918, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4329, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
