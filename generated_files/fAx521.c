#include "stdafx.h"
#include "fAx521.h"

int fAx521(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_21_1, bmats.A_21_10, bmats.A_21_11, bmats.A_21_12, bmats.A_21_15, bmats.A_21_16, bmats.A_21_2, bmats.A_21_3, bmats.A_21_4, bmats.A_21_5, bmats.A_21_6, bmats.A_21_7, bmats.A_21_8, bmats.A_21_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax521, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
