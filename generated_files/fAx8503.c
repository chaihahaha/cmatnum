#include "stdafx.h"
#include "fAx8503.h"

int fAx8503(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_17_31, bmats.A_17_32, bmats.A_18_31, bmats.A_18_32, bmats.A_19_31, bmats.A_19_32, bmats.A_22_31, bmats.A_22_32, bmats.A_23_31, bmats.A_23_32, bmats.A_24_31, bmats.A_24_32, bmats.A_25_31, bmats.A_25_32, bmats.A_26_31, bmats.A_26_32, bmats.A_27_31, bmats.A_27_32, bmats.A_28_31, bmats.A_28_32, bmats.A_29_31, bmats.A_29_32, bmats.A_30_31, bmats.A_30_32, bmats.A_31_31, bmats.A_31_32, bmats.A_32_32, bmats.Ax600, bmats.Ax604, bmats.Ax609, bmats.Ax612, bmats.Ax615, bmats.Ax618, bmats.Ax621, bmats.Ax624, bmats.Ax627, bmats.Ax630, bmats.Ax639, bmats.Ax664, bmats.Ax667, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, -17, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax8503, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
