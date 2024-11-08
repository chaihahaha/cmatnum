#include "stdafx.h"
#include "fAx3774.h"

int fAx3774(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_7_1, bmats.A_7_10, bmats.A_7_11, bmats.A_7_12, bmats.A_7_13, bmats.A_7_14, bmats.A_7_2, bmats.A_7_3, bmats.A_7_4, bmats.A_7_5, bmats.A_7_6, bmats.A_7_7, bmats.A_7_8, bmats.A_7_9, };
    double A_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax3774, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
