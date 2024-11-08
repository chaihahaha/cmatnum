#include "stdafx.h"
#include "fAx2911.h"

int fAx2911(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_26_1, bmats.A_26_10, bmats.A_26_11, bmats.A_26_12, bmats.A_26_15, bmats.A_26_16, bmats.A_26_2, bmats.A_26_3, bmats.A_26_4, bmats.A_26_5, bmats.A_26_6, bmats.A_26_7, bmats.A_26_8, bmats.A_26_9, bmats.Ax2874, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax2911, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
