#include "stdafx.h"
#include "fAx7543.h"

int fAx7543(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.A_29_21, bmats.A_29_22, bmats.A_29_23, bmats.A_29_24, bmats.A_29_25, bmats.A_29_26, bmats.A_29_27, bmats.A_29_28, bmats.A_29_30, };
    double A_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7543, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
