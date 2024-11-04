#include "stdafx.h"
#include "fAx6763.h"

int fAx6763(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_30_17, bmats.A_30_18, bmats.A_30_19, bmats.A_30_20, bmats.A_30_21, bmats.A_30_22, bmats.A_30_23, bmats.A_30_24, bmats.A_30_25, bmats.A_30_26, bmats.A_30_29, bmats.A_30_30, bmats.A_30_31, bmats.A_30_32, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax6763, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
