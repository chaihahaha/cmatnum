#include "stdafx.h"
#include "fAx4775.h"

int fAx4775(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_17, bmats.A_10_18, bmats.A_11_17, bmats.A_11_18, bmats.A_12_17, bmats.A_12_18, bmats.A_13_17, bmats.A_13_18, bmats.A_14_17, bmats.A_14_18, bmats.A_15_17, bmats.A_15_18, bmats.A_16_17, bmats.A_16_18, bmats.A_1_17, bmats.A_1_18, bmats.A_2_17, bmats.A_2_18, bmats.A_3_17, bmats.A_3_18, bmats.A_4_17, bmats.A_4_18, bmats.A_5_17, bmats.A_5_18, bmats.A_6_17, bmats.A_6_18, bmats.A_7_17, bmats.A_7_18, bmats.A_8_17, bmats.A_8_18, bmats.A_9_17, bmats.A_9_18, bmats.Ax1766, bmats.Ax2128, bmats.Ax2636, bmats.Ax2885, bmats.Ax3111, bmats.Ax3338, bmats.Ax3723, bmats.Ax3878, bmats.Ax4084, bmats.Ax4395, bmats.Ax4530, bmats.Ax4589, bmats.Ax4680, bmats.Ax4683, bmats.Ax4686, bmats.Ax658, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4775, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
