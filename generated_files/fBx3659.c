#include "stdafx.h"
#include "fBx3659.h"

inline int fBx3659(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_5, bmats.B_5_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3659.data[0][0], 0, sizeof(bmats.Bx3659.data[0][0])*bmats.Bx3659.shape[0]*bmats.Bx3659.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3659, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}