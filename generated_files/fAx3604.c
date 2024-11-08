#include "stdafx.h"
#include "fAx3604.h"

int fAx3604(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_24_1, bmats.A_24_10, bmats.A_24_11, bmats.A_24_12, bmats.A_24_13, bmats.A_24_14, bmats.A_24_15, bmats.A_24_16, bmats.A_24_2, bmats.A_24_5, bmats.A_24_6, bmats.A_24_7, bmats.A_24_8, bmats.A_24_9, bmats.Ax3450, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3604, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
