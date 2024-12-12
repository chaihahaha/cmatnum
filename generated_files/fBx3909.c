#include "stdafx.h"
#include "fBx3909.h"

inline int fBx3909(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_1, bmats.B_1_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3909.data[0][0], 0, sizeof(bmats.Bx3909.data[0][0])*bmats.Bx3909.shape[0]*bmats.Bx3909.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3909, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
