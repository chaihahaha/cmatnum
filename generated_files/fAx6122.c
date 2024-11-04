#include "stdafx.h"
#include "fAx6122.h"

int fAx6122(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_20_17, bmats.A_20_18, bmats.A_20_19, bmats.A_20_21, bmats.A_20_22, bmats.A_20_23, bmats.A_20_24, bmats.A_20_25, bmats.A_20_26, bmats.A_20_27, bmats.A_20_30, bmats.A_20_31, };
    double A_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6122, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
