#include "stdafx.h"
#include "fAx8340.h"

int fAx8340(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_26_17, bmats.A_26_19, bmats.A_26_23, bmats.A_26_24, bmats.A_26_25, bmats.A_26_27, bmats.A_26_31, bmats.A_26_32, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8340, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
