#include "stdafx.h"
#include "fAx2309.h"

int fAx2309(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_1_17, bmats.A_1_18, bmats.A_1_19, bmats.A_1_20, bmats.A_1_21, bmats.A_1_22, bmats.A_1_23, bmats.A_1_24, bmats.A_1_25, bmats.A_1_26, bmats.A_1_29, bmats.A_1_30, bmats.A_1_31, bmats.A_1_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2309, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
