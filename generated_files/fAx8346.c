#include "stdafx.h"
#include "fAx8346.h"

int fAx8346(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_26_17, bmats.A_26_19, bmats.A_26_21, bmats.A_26_25, bmats.A_26_27, bmats.A_26_31, bmats.A_26_32, };
    double A_coeffs[7] = {-1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax8346, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
