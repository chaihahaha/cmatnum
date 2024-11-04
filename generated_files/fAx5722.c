#include "stdafx.h"
#include "fAx5722.h"

int fAx5722(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_8_1, bmats.A_8_10, bmats.A_8_11, bmats.A_8_12, bmats.A_8_13, bmats.A_8_14, bmats.A_8_15, bmats.A_8_16, bmats.A_8_2, bmats.A_8_5, bmats.A_8_6, bmats.A_8_7, bmats.A_8_9, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5722, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
