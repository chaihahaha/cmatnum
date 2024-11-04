#include "stdafx.h"
#include "fAx5307.h"

int fAx5307(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_1, bmats.A_12_11, bmats.A_12_13, bmats.A_12_14, bmats.A_12_15, bmats.A_12_16, bmats.A_12_2, bmats.A_12_3, bmats.A_12_4, bmats.A_12_5, bmats.A_12_6, bmats.A_12_7, bmats.A_12_8, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5307, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
