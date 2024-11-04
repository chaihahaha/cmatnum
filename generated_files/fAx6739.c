#include "stdafx.h"
#include "fAx6739.h"

int fAx6739(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_31_17, bmats.A_31_18, bmats.A_31_19, bmats.A_31_20, bmats.A_31_21, bmats.A_31_22, bmats.A_31_23, bmats.A_31_24, bmats.A_31_25, bmats.A_31_26, bmats.A_31_29, bmats.A_31_30, bmats.A_31_31, bmats.A_31_32, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, 2, };
    matlincomb_double_contiguous(bmats.Ax6739, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
