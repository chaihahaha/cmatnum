#include "stdafx.h"
#include "fAx8236.h"

int fAx8236(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_16_1, bmats.A_16_10, bmats.A_16_11, bmats.A_16_14, bmats.A_16_15, bmats.A_16_16, bmats.A_16_2, bmats.A_16_3, bmats.A_16_4, bmats.A_16_5, bmats.A_16_6, bmats.A_16_7, bmats.A_16_8, bmats.A_16_9, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, -15, 2, 2, 2, 2, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax8236, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
