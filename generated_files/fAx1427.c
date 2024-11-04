#include "stdafx.h"
#include "fAx1427.h"

int fAx1427(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_14_17, bmats.A_14_18, bmats.A_14_19, bmats.A_14_20, bmats.A_14_21, bmats.A_14_22, bmats.A_14_25, bmats.A_14_26, bmats.A_14_27, bmats.A_14_28, bmats.A_14_29, bmats.A_14_30, bmats.A_14_31, bmats.A_14_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax1427, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
