#include "stdafx.h"
#include "fAx2845.h"

int fAx2845(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_8_17, bmats.A_8_18, bmats.A_8_19, bmats.A_8_20, bmats.A_8_21, bmats.A_8_22, bmats.A_8_23, bmats.A_8_24, bmats.A_8_27, bmats.A_8_28, bmats.A_8_29, bmats.A_8_30, bmats.A_8_31, bmats.A_8_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2845, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
