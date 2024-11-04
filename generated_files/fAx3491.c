#include "stdafx.h"
#include "fAx3491.h"

int fAx3491(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 42;
    double_cmat A_mats[42] = {bmats.A_10_7, bmats.A_10_8, bmats.A_11_7, bmats.A_11_8, bmats.A_12_7, bmats.A_12_8, bmats.A_13_7, bmats.A_13_8, bmats.A_14_7, bmats.A_14_8, bmats.A_15_7, bmats.A_15_8, bmats.A_16_7, bmats.A_16_8, bmats.A_1_7, bmats.A_1_8, bmats.A_2_7, bmats.A_2_8, bmats.A_4_7, bmats.A_4_8, bmats.A_5_7, bmats.A_5_8, bmats.A_6_7, bmats.A_6_8, bmats.A_7_7, bmats.A_7_8, bmats.A_9_7, bmats.A_9_8, bmats.Ax1391, bmats.Ax2034, bmats.Ax2460, bmats.Ax2732, bmats.Ax2989, bmats.Ax3252, bmats.Ax3455, bmats.Ax3458, bmats.Ax3464, bmats.Ax3467, bmats.Ax3470, bmats.Ax3473, bmats.Ax3476, bmats.Ax3489, };
    double A_coeffs[42] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3491, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
