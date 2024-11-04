#include "stdafx.h"
#include "fAx6620.h"

int fAx6620(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_17_18, bmats.A_17_20, bmats.A_17_21, bmats.A_17_22, bmats.A_17_23, bmats.A_17_24, bmats.A_17_27, bmats.A_17_28, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6620, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
