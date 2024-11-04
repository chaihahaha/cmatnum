#include "stdafx.h"
#include "fAx6059.h"

int fAx6059(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_21_22, bmats.A_21_23, bmats.A_21_24, bmats.A_21_25, bmats.A_21_26, bmats.A_21_28, bmats.A_21_29, bmats.A_21_30, bmats.A_21_31, bmats.A_21_32, };
    double A_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6059, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
