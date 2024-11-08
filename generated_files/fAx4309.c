#include "stdafx.h"
#include "fAx4309.h"

int fAx4309(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_17_1, bmats.A_17_10, bmats.A_17_11, bmats.A_17_12, bmats.A_17_13, bmats.A_17_14, bmats.A_17_15, bmats.A_17_16, bmats.A_17_2, bmats.A_17_5, bmats.A_17_6, bmats.A_17_7, bmats.A_17_8, bmats.A_17_9, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4309, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
