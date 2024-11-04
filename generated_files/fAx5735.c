#include "stdafx.h"
#include "fAx5735.h"

int fAx5735(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_6_1, bmats.A_6_10, bmats.A_6_11, bmats.A_6_12, bmats.A_6_13, bmats.A_6_14, bmats.A_6_15, bmats.A_6_16, bmats.A_6_2, bmats.A_6_5, bmats.A_6_7, bmats.A_6_8, bmats.A_6_9, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5735, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
