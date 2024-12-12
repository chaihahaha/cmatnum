#include "stdafx.h"
#include "fBx3046.h"

inline int fBx3046(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_29_27, bmats.B_29_28, bmats.B_29_31, bmats.B_29_32, bmats.Bx1353, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx3046.data[0][0], 0, sizeof(bmats.Bx3046.data[0][0])*bmats.Bx3046.shape[0]*bmats.Bx3046.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3046, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
