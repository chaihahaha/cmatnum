#include "stdafx.h"
#include "fBx12422.h"

int fBx12422(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_12_19, bmats.B_13_19, bmats.B_15_19, bmats.B_16_19, bmats.B_1_19, bmats.B_2_19, bmats.B_3_19, bmats.B_4_19, bmats.B_5_19, bmats.B_6_19, bmats.B_7_19, bmats.B_8_19, bmats.B_9_19, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12422, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
