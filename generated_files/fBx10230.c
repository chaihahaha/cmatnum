#include "stdafx.h"
#include "fBx10230.h"

inline int fBx10230(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_29_17, bmats.B_29_21, bmats.B_29_25, bmats.B_29_26, bmats.Bx3046, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx10230.data[0][0], 0, sizeof(bmats.Bx10230.data[0][0])*bmats.Bx10230.shape[0]*bmats.Bx10230.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10230, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
