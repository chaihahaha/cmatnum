#include "stdafx.h"
#include "fBx11171.h"

inline int fBx11171(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_22, bmats.B_12_22, bmats.B_13_22, bmats.B_8_22, bmats.Bx10908, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11171.data[0][0], 0, sizeof(bmats.Bx11171.data[0][0])*bmats.Bx11171.shape[0]*bmats.Bx11171.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11171, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
