#include "stdafx.h"
#include "fBx11629.h"

inline int fBx11629(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_21_21, bmats.B_23_21, bmats.B_24_21, bmats.B_26_21, bmats.Bx11617, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11629.data[0][0], 0, sizeof(bmats.Bx11629.data[0][0])*bmats.Bx11629.shape[0]*bmats.Bx11629.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11629, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
