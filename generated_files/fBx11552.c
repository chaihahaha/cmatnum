#include "stdafx.h"
#include "fBx11552.h"

inline int fBx11552(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_5, bmats.B_5_21, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11552.data[0][0], 0, sizeof(bmats.Bx11552.data[0][0])*bmats.Bx11552.shape[0]*bmats.Bx11552.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11552, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
