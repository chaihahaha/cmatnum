#include "stdafx.h"
#include "fAx6147.h"

int fAx6147(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_20_17, bmats.A_20_19, bmats.A_20_24, bmats.A_20_25, bmats.A_20_26, bmats.A_20_27, bmats.A_20_31, };
    double A_coeffs[7] = {-1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6147, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
