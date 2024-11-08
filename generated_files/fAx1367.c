#include "stdafx.h"
#include "fAx1367.h"

int fAx1367(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_13_17, bmats.A_13_18, bmats.A_13_19, bmats.A_13_20, bmats.A_13_21, bmats.A_13_22, bmats.A_13_23, bmats.A_13_24, bmats.A_13_25, bmats.A_13_26, bmats.A_13_27, bmats.A_13_28, bmats.A_13_29, bmats.A_13_31, bmats.A_13_32, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax1367, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
