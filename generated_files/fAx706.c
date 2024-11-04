#include "stdafx.h"
#include "fAx706.h"

int fAx706(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_19_1, bmats.A_19_10, bmats.A_19_11, bmats.A_19_12, bmats.A_19_13, bmats.A_19_14, bmats.A_19_2, bmats.A_19_3, bmats.A_19_4, bmats.A_19_5, bmats.A_19_6, bmats.A_19_7, bmats.A_19_8, bmats.A_19_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax706, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
