#include "stdafx.h"
#include "fAx7485.h"

int fAx7485(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_2_1, bmats.A_2_10, bmats.A_2_11, bmats.A_2_12, bmats.A_2_13, bmats.A_2_14, bmats.A_2_15, bmats.A_2_16, bmats.A_2_2, bmats.A_2_3, bmats.A_2_4, bmats.A_2_5, bmats.A_2_8, bmats.A_2_9, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, -15, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax7485, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
