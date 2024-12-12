#include "stdafx.h"
#include "fBx11625.h"

inline int fBx11625(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11435, bmats.Bx11624, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11625.data[0][0], 0, sizeof(bmats.Bx11625.data[0][0])*bmats.Bx11625.shape[0]*bmats.Bx11625.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11625, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
