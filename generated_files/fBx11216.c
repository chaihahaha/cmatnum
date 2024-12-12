#include "stdafx.h"
#include "fBx11216.h"

inline int fBx11216(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_6_22, bmats.B_6_31, bmats.Bx10646, bmats.Bx11215, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11216.data[0][0], 0, sizeof(bmats.Bx11216.data[0][0])*bmats.Bx11216.shape[0]*bmats.Bx11216.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11216, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
