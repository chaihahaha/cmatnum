#include "fAx3817.h"
#include "stdafx.h"

inline int fAx3817(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_7, bmats.A_10_8, bmats.A_11_7, bmats.A_11_8, bmats.A_12_7, bmats.A_12_8, bmats.A_13_7, bmats.A_13_8, bmats.A_14_7, bmats.A_14_8, bmats.A_15_7, bmats.A_15_8, bmats.A_16_7, bmats.A_16_8, bmats.A_1_7, bmats.A_1_8, bmats.A_2_7, bmats.A_2_8, bmats.A_3_7, bmats.A_3_8, bmats.A_4_7, bmats.A_4_8, bmats.A_7_7, bmats.A_8_7, bmats.A_8_8, bmats.A_9_7, bmats.A_9_8, bmats.Ax1391, bmats.Ax2034, bmats.Ax2460, bmats.Ax2732, bmats.Ax2989, bmats.Ax3252, bmats.Ax3455, bmats.Ax3461, bmats.Ax3464, bmats.Ax3473, bmats.Ax3476, bmats.Ax3486, bmats.Ax3489, };
    double A_coeffs[40] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -17, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3817, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
