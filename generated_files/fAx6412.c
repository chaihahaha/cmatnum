#include "stdafx.h"
#include "fAx6412.h"

int fAx6412(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_22_18, bmats.A_22_19, bmats.A_22_23, bmats.A_22_24, bmats.A_22_25, bmats.A_22_26, bmats.A_22_27, bmats.A_22_28, bmats.A_22_29, bmats.A_22_30, bmats.A_22_31, bmats.A_22_32, };
    double A_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6412, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
