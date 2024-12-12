#include "stdafx.h"
#include "fBx11926.h"

inline int fBx11926(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11924, bmats.Bx11925, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11926.data[0][0], 0, sizeof(bmats.Bx11926.data[0][0])*bmats.Bx11926.shape[0]*bmats.Bx11926.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11926, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
