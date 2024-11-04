#include "stdafx.h"
#include "fAx7772.h"

int fAx7772(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_1_1, bmats.A_1_10, bmats.A_1_11, bmats.A_1_12, bmats.A_1_13, bmats.A_1_14, bmats.A_1_2, bmats.A_1_3, bmats.A_1_4, bmats.A_1_5, bmats.A_1_6, bmats.A_1_7, bmats.A_1_8, bmats.A_1_9, };
    double A_coeffs[14] = {-15, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax7772, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
