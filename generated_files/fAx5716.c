#include "stdafx.h"
#include "fAx5716.h"

int fAx5716(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_10_1, bmats.A_10_11, bmats.A_10_12, bmats.A_10_13, bmats.A_10_14, bmats.A_10_15, bmats.A_10_16, bmats.A_10_2, bmats.A_10_5, bmats.A_10_6, bmats.A_10_7, bmats.A_10_8, bmats.A_10_9, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5716, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
