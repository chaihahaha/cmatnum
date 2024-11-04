#include "stdafx.h"
#include "fAx2813.h"

int fAx2813(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_26_1, bmats.A_26_11, bmats.A_26_12, bmats.A_26_13, bmats.A_26_14, bmats.A_26_15, bmats.A_26_16, bmats.A_26_2, bmats.A_26_3, bmats.A_26_4, bmats.A_26_5, bmats.A_26_6, bmats.A_26_7, bmats.A_26_8, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2813, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
