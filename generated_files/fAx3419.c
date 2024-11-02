#include "fAx3419.h"

inline int fAx3419(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_7, bmats.A_17_8, bmats.A_18_7, bmats.A_18_8, bmats.A_19_7, bmats.A_19_8, bmats.A_20_7, bmats.A_20_8, bmats.A_21_7, bmats.A_21_8, bmats.A_22_7, bmats.A_22_8, bmats.A_23_7, bmats.A_23_8, bmats.A_24_7, bmats.A_24_8, bmats.A_25_7, bmats.A_25_8, bmats.A_26_7, bmats.A_26_8, bmats.A_27_7, bmats.A_27_8, bmats.A_28_7, bmats.A_28_8, bmats.A_29_7, bmats.A_29_8, bmats.A_30_7, bmats.A_30_8, bmats.A_31_7, bmats.A_31_8, bmats.A_32_7, bmats.A_32_8, bmats.Ax1422, bmats.Ax2109, bmats.Ax2454, bmats.Ax2726, bmats.Ax3002, bmats.Ax3322, bmats.Ax3390, bmats.Ax3393, bmats.Ax3396, bmats.Ax3399, bmats.Ax3402, bmats.Ax3405, bmats.Ax3408, bmats.Ax3411, bmats.Ax3414, bmats.Ax3417, };
    double A_coeffs[48] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3419, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
