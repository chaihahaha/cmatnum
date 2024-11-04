#include "stdafx.h"
#include "fAx4223.h"

int fAx4223(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_21_1, bmats.A_21_10, bmats.A_21_11, bmats.A_21_12, bmats.A_21_13, bmats.A_21_14, bmats.A_21_15, bmats.A_21_16, bmats.A_21_3, bmats.A_21_4, bmats.A_21_5, bmats.A_21_6, bmats.A_21_8, bmats.A_21_9, bmats.Ax4126, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4223, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
