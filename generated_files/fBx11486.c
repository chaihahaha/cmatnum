#include "stdafx.h"
#include "fBx11486.h"

inline int fBx11486(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_5, bmats.B_11_5, bmats.B_1_5, bmats.B_5_5, bmats.B_8_5, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11486.data[0][0], 0, sizeof(bmats.Bx11486.data[0][0])*bmats.Bx11486.shape[0]*bmats.Bx11486.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11486, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}