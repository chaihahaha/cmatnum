#include "stdafx.h"
#include "fAx2303.h"

int fAx2303(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_7_17, bmats.A_7_18, bmats.A_7_19, bmats.A_7_20, bmats.A_7_21, bmats.A_7_22, bmats.A_7_23, bmats.A_7_24, bmats.A_7_25, bmats.A_7_26, bmats.A_7_29, bmats.A_7_30, bmats.A_7_31, bmats.A_7_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2303, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
