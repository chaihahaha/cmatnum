#include "fAx3157.h"

inline int fAx3157(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_10, bmats.A_17_9, bmats.A_18_10, bmats.A_18_9, bmats.A_19_10, bmats.A_19_9, bmats.A_20_10, bmats.A_20_9, bmats.A_21_10, bmats.A_21_9, bmats.A_22_10, bmats.A_22_9, bmats.A_23_10, bmats.A_23_9, bmats.A_24_10, bmats.A_24_9, bmats.A_25_10, bmats.A_25_9, bmats.A_26_10, bmats.A_26_9, bmats.A_27_10, bmats.A_27_9, bmats.A_28_10, bmats.A_28_9, bmats.A_29_10, bmats.A_29_9, bmats.A_30_10, bmats.A_30_9, bmats.A_31_10, bmats.A_31_9, bmats.A_32_10, bmats.A_32_9, bmats.Ax1484, bmats.Ax2044, bmats.Ax2384, bmats.Ax2671, bmats.Ax2801, bmats.Ax2804, bmats.Ax2807, bmats.Ax2810, bmats.Ax2813, bmats.Ax2816, bmats.Ax2819, bmats.Ax2822, bmats.Ax2825, bmats.Ax2828, bmats.Ax2831, bmats.Ax2834, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3157, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
