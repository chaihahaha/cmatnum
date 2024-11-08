#include "stdafx.h"
#include "fAx6819.h"

int fAx6819(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_27_19, bmats.A_27_20, bmats.A_27_21, bmats.A_27_24, bmats.A_27_25, bmats.A_27_26, bmats.A_27_28, bmats.A_27_29, bmats.A_27_30, bmats.A_27_31, bmats.A_27_32, };
    double A_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6819, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
