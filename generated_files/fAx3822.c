#include "stdafx.h"
#include "fAx3822.h"

int fAx3822(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_23_1, bmats.A_23_10, bmats.A_23_11, bmats.A_23_12, bmats.A_23_13, bmats.A_23_14, bmats.A_23_15, bmats.A_23_16, bmats.A_23_2, bmats.A_23_3, bmats.A_23_4, bmats.A_23_7, bmats.A_23_8, bmats.A_23_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3822, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
