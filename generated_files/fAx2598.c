#include "fAx2598.h"

inline int fAx2598(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_11, bmats.A_17_12, bmats.A_18_11, bmats.A_18_12, bmats.A_19_11, bmats.A_19_12, bmats.A_20_11, bmats.A_20_12, bmats.A_21_11, bmats.A_21_12, bmats.A_22_11, bmats.A_22_12, bmats.A_23_11, bmats.A_23_12, bmats.A_24_11, bmats.A_24_12, bmats.A_25_11, bmats.A_25_12, bmats.A_26_11, bmats.A_26_12, bmats.A_27_11, bmats.A_27_12, bmats.A_28_11, bmats.A_28_12, bmats.A_29_11, bmats.A_29_12, bmats.A_30_11, bmats.A_30_12, bmats.A_31_11, bmats.A_31_12, bmats.A_32_11, bmats.A_32_12, bmats.Ax1224, bmats.Ax1981, bmats.Ax2236, bmats.Ax2239, bmats.Ax2242, bmats.Ax2245, bmats.Ax2248, bmats.Ax2251, bmats.Ax2254, bmats.Ax2257, bmats.Ax2260, bmats.Ax2263, bmats.Ax2266, bmats.Ax2269, bmats.Ax2272, bmats.Ax2275, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2598, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
