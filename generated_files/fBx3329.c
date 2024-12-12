#include "stdafx.h"
#include "fBx3329.h"

inline int fBx3329(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_32, bmats.B_32_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3329.data[0][0], 0, sizeof(bmats.Bx3329.data[0][0])*bmats.Bx3329.shape[0]*bmats.Bx3329.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3329, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
