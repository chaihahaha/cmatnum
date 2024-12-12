#include "stdafx.h"
#include "fBx11710.h"

inline int fBx11710(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11205, bmats.Bx11709, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11710.data[0][0], 0, sizeof(bmats.Bx11710.data[0][0])*bmats.Bx11710.shape[0]*bmats.Bx11710.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11710, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
