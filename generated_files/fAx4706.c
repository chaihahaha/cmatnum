#include "stdafx.h"
#include "fAx4706.h"

int fAx4706(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_18_1, bmats.A_18_10, bmats.A_18_13, bmats.A_18_14, bmats.A_18_15, bmats.A_18_16, bmats.A_18_2, bmats.A_18_3, bmats.A_18_4, bmats.A_18_5, bmats.A_18_6, bmats.A_18_7, bmats.A_18_8, bmats.A_18_9, bmats.Ax4688, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4706, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
