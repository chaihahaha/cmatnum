#include "stdafx.h"
#include "fAx4573.h"

int fAx4573(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_19_1, bmats.A_19_10, bmats.A_19_11, bmats.A_19_12, bmats.A_19_13, bmats.A_19_14, bmats.A_19_15, bmats.A_19_16, bmats.A_19_2, bmats.A_19_3, bmats.A_19_5, bmats.A_19_6, bmats.A_19_7, bmats.A_19_8, bmats.Ax4519, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax4573, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
