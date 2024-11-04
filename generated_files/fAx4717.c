#include "stdafx.h"
#include "fAx4717.h"

int fAx4717(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_18_1, bmats.A_18_11, bmats.A_18_12, bmats.A_18_13, bmats.A_18_14, bmats.A_18_15, bmats.A_18_16, bmats.A_18_2, bmats.A_18_3, bmats.A_18_5, bmats.A_18_6, bmats.A_18_7, bmats.A_18_8, bmats.A_18_9, bmats.Ax4688, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4717, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
