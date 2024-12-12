#include "stdafx.h"
#include "fBx11623.h"

inline int fBx11623(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_5, bmats.Bx11437, bmats.Bx11486, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11623.data[0][0], 0, sizeof(bmats.Bx11623.data[0][0])*bmats.Bx11623.shape[0]*bmats.Bx11623.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11623, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
