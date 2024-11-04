#include "stdafx.h"
#include "fAx6381.h"

int fAx6381(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.A_18_17, bmats.A_18_22, bmats.A_18_23, bmats.A_18_27, bmats.A_18_28, bmats.A_18_29, bmats.A_18_30, bmats.A_18_31, };
    double A_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax6381, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
