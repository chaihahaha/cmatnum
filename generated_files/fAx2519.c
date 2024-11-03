#include "fAx2519.h"
#include "stdafx.h"

inline int fAx2519(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_11, bmats.A_10_12, bmats.A_11_11, bmats.A_11_12, bmats.A_12_12, bmats.A_13_11, bmats.A_13_12, bmats.A_14_11, bmats.A_14_12, bmats.A_15_11, bmats.A_15_12, bmats.A_16_11, bmats.A_16_12, bmats.A_2_11, bmats.A_2_12, bmats.A_3_11, bmats.A_3_12, bmats.A_4_11, bmats.A_4_12, bmats.A_5_11, bmats.A_5_12, bmats.A_7_11, bmats.A_7_12, bmats.A_8_11, bmats.A_8_12, bmats.A_9_11, bmats.A_9_12, bmats.Ax1255, bmats.Ax1969, bmats.Ax2178, bmats.Ax2181, bmats.Ax2184, bmats.Ax2187, bmats.Ax2190, bmats.Ax2196, bmats.Ax2199, bmats.Ax2202, bmats.Ax2208, bmats.Ax2211, bmats.Ax2214, };
    double A_coeffs[40] = {1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2519, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
