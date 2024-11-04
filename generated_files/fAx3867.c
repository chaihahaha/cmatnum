#include "stdafx.h"
#include "fAx3867.h"

int fAx3867(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_21, bmats.A_10_22, bmats.A_11_21, bmats.A_11_22, bmats.A_12_21, bmats.A_12_22, bmats.A_13_21, bmats.A_13_22, bmats.A_14_21, bmats.A_14_22, bmats.A_15_21, bmats.A_15_22, bmats.A_16_21, bmats.A_16_22, bmats.A_1_21, bmats.A_1_22, bmats.A_2_21, bmats.A_2_22, bmats.A_3_21, bmats.A_3_22, bmats.A_4_21, bmats.A_4_22, bmats.A_5_21, bmats.A_5_22, bmats.A_6_21, bmats.A_6_22, bmats.A_7_21, bmats.A_7_22, bmats.A_8_21, bmats.A_8_22, bmats.A_9_21, bmats.A_9_22, bmats.Ax1630, bmats.Ax2080, bmats.Ax2442, bmats.Ax2783, bmats.Ax3071, bmats.Ax3296, bmats.Ax3538, bmats.Ax3825, bmats.Ax3844, bmats.Ax3847, bmats.Ax3850, bmats.Ax3853, bmats.Ax3856, bmats.Ax3859, bmats.Ax3862, bmats.Ax3865, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3867, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
