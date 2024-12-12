#include "stdafx.h"
#include "fBx11060.h"

inline int fBx11060(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_29_18, bmats.B_29_23, bmats.B_29_24, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11060.data[0][0], 0, sizeof(bmats.Bx11060.data[0][0])*bmats.Bx11060.shape[0]*bmats.Bx11060.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11060, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
