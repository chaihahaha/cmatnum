#include "stdafx.h"
#include "fAx8267.h"

int fAx8267(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_32_1, bmats.A_32_10, bmats.A_32_11, bmats.A_32_12, bmats.A_32_13, bmats.A_32_15, bmats.A_32_2, bmats.A_32_3, bmats.A_32_4, bmats.A_32_5, bmats.A_32_6, bmats.A_32_7, bmats.A_32_8, bmats.A_32_9, bmats.Ax7798, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax8267, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
