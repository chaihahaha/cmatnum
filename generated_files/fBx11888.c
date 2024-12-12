#include "stdafx.h"
#include "fBx11888.h"

inline int fBx11888(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx10542, bmats.Bx11887, bmats.Bx1845, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11888.data[0][0], 0, sizeof(bmats.Bx11888.data[0][0])*bmats.Bx11888.shape[0]*bmats.Bx11888.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11888, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
