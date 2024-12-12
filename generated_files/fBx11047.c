#include "stdafx.h"
#include "fBx11047.h"

inline int fBx11047(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_14_6, bmats.Bx10891, bmats.Bx11045, bmats.Bx11046, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11047.data[0][0], 0, sizeof(bmats.Bx11047.data[0][0])*bmats.Bx11047.shape[0]*bmats.Bx11047.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11047, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
