#include "stdafx.h"
#include "fBx10552.h"

inline int fBx10552(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_5_8, bmats.Bx10551, bmats.Bx7765, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10552.data[0][0], 0, sizeof(bmats.Bx10552.data[0][0])*bmats.Bx10552.shape[0]*bmats.Bx10552.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10552, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
