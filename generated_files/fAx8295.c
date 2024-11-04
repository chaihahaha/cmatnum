#include "stdafx.h"
#include "fAx8295.h"

int fAx8295(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_13_1, bmats.A_13_10, bmats.A_13_11, bmats.A_13_12, bmats.A_13_13, bmats.A_13_14, bmats.A_13_15, bmats.A_13_16, bmats.A_13_2, bmats.A_13_3, bmats.A_13_6, bmats.A_13_7, bmats.A_13_8, bmats.A_13_9, };
    double A_coeffs[14] = {2, 2, 2, 2, -15, 2, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8295, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
