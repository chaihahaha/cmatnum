#include "stdafx.h"
#include "fAx8483.h"

int fAx8483(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_31_1, bmats.A_31_10, bmats.A_31_11, bmats.A_31_12, bmats.A_31_13, bmats.A_31_14, bmats.A_31_15, bmats.A_31_16, bmats.A_31_2, bmats.A_31_3, bmats.A_31_4, bmats.A_31_5, bmats.A_31_6, bmats.A_31_7, bmats.Ax791, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax8483, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
