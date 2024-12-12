#include "stdafx.h"
#include "fBx11210.h"

inline int fBx11210(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_22_15, bmats.B_22_16, bmats.B_22_5, bmats.B_22_6, bmats.Bx10637, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx11210.data[0][0], 0, sizeof(bmats.Bx11210.data[0][0])*bmats.Bx11210.shape[0]*bmats.Bx11210.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11210, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
