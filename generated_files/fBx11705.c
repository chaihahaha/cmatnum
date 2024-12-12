#include "stdafx.h"
#include "fBx11705.h"

inline int fBx11705(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_15, bmats.B_6_2, bmats.Bx10617, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11705.data[0][0], 0, sizeof(bmats.Bx11705.data[0][0])*bmats.Bx11705.shape[0]*bmats.Bx11705.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11705, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
