#include "stdafx.h"
#include "fAx6926.h"

int fAx6926(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_24_17, bmats.A_24_18, bmats.A_24_19, bmats.A_24_20, bmats.A_24_21, bmats.A_24_22, bmats.A_24_23, bmats.A_24_25, bmats.A_24_28, bmats.A_24_29, bmats.A_24_30, bmats.A_24_31, };
    double A_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6926, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
