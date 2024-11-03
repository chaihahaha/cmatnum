#include "fAx3669.h"
#include "stdafx.h"

inline int fAx3669(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 42;
    double_cmat A_mats[42] = {bmats.A_17_23, bmats.A_17_24, bmats.A_18_23, bmats.A_18_24, bmats.A_20_23, bmats.A_20_24, bmats.A_21_23, bmats.A_21_24, bmats.A_22_23, bmats.A_22_24, bmats.A_24_23, bmats.A_24_24, bmats.A_25_23, bmats.A_25_24, bmats.A_26_23, bmats.A_26_24, bmats.A_27_23, bmats.A_27_24, bmats.A_28_23, bmats.A_28_24, bmats.A_29_23, bmats.A_29_24, bmats.A_30_23, bmats.A_30_24, bmats.A_31_23, bmats.A_31_24, bmats.A_32_23, bmats.A_32_24, bmats.Ax115, bmats.Ax1370, bmats.Ax2031, bmats.Ax321, bmats.Ax3381, bmats.Ax3384, bmats.Ax340, bmats.Ax347, bmats.Ax350, bmats.Ax354, bmats.Ax50, bmats.Ax7, bmats.Ax79, bmats.Ax82, };
    double A_coeffs[42] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3669, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
