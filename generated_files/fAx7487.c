#include "stdafx.h"
#include "fAx7487.h"

int fAx7487(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_4_1, bmats.A_4_10, bmats.A_4_11, bmats.A_4_12, bmats.A_4_13, bmats.A_4_14, bmats.A_4_15, bmats.A_4_2, bmats.A_4_3, bmats.A_4_4, bmats.A_4_6, bmats.A_4_7, bmats.A_4_8, bmats.A_4_9, };
    double A_coeffs[14] = {2, 2, 2, 2, 2, 2, 2, 2, 2, -15, 2, 2, 2, 2, };
    matlincomb_double_contiguous(bmats.Ax7487, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
