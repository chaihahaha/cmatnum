#include "stdafx.h"
#include "fAx5847.h"

int fAx5847(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_11_10, bmats.A_11_11, bmats.A_11_12, bmats.A_11_13, bmats.A_11_14, bmats.A_11_15, bmats.A_11_16, bmats.A_11_3, bmats.A_11_4, bmats.A_11_5, bmats.A_11_6, bmats.A_11_7, bmats.A_11_8, bmats.A_11_9, };
    double A_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax5847, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
