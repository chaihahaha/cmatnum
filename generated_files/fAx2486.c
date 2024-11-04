#include "stdafx.h"
#include "fAx2486.h"

int fAx2486(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_12_17, bmats.A_12_18, bmats.A_12_21, bmats.A_12_22, bmats.A_12_23, bmats.A_12_24, bmats.A_12_25, bmats.A_12_26, bmats.A_12_27, bmats.A_12_28, bmats.A_12_29, bmats.A_12_30, bmats.A_12_31, bmats.A_12_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax2486, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
