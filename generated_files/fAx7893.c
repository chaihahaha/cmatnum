#include "stdafx.h"
#include "fAx7893.h"

int fAx7893(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_31_19, bmats.A_31_20, bmats.A_31_21, bmats.A_31_22, bmats.A_31_23, bmats.A_31_26, bmats.A_31_27, bmats.A_31_28, bmats.A_31_29, bmats.A_31_30, bmats.A_31_32, };
    double A_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7893, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
