#include "stdafx.h"
#include "fAx5429.h"

int fAx5429(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_1, bmats.A_14_10, bmats.A_14_11, bmats.A_14_12, bmats.A_14_13, bmats.A_14_15, bmats.A_14_16, bmats.A_14_2, bmats.A_14_3, bmats.A_14_4, bmats.A_14_5, bmats.A_14_6, bmats.A_14_9, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5429, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
