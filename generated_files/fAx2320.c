#include "stdafx.h"
#include "fAx2320.h"

int fAx2320(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_27, bmats.A_10_28, bmats.A_11_27, bmats.A_11_28, bmats.A_12_27, bmats.A_12_28, bmats.A_13_27, bmats.A_13_28, bmats.A_14_27, bmats.A_14_28, bmats.A_15_27, bmats.A_15_28, bmats.A_16_27, bmats.A_16_28, bmats.A_1_27, bmats.A_1_28, bmats.A_2_27, bmats.A_2_28, bmats.A_3_27, bmats.A_3_28, bmats.A_4_27, bmats.A_4_28, bmats.A_5_27, bmats.A_5_28, bmats.A_6_27, bmats.A_6_28, bmats.A_7_27, bmats.A_7_28, bmats.A_8_27, bmats.A_8_28, bmats.A_9_27, bmats.A_9_28, bmats.Ax1229, bmats.Ax1963, bmats.Ax2279, bmats.Ax2282, bmats.Ax2285, bmats.Ax2288, bmats.Ax2291, bmats.Ax2294, bmats.Ax2297, bmats.Ax2300, bmats.Ax2303, bmats.Ax2306, bmats.Ax2309, bmats.Ax2312, bmats.Ax2315, bmats.Ax2318, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2320, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
