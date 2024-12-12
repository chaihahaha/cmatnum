#include "stdafx.h"
#include "fBx10519.h"

inline int fBx10519(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_7, bmats.B_4_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10519.data[0][0], 0, sizeof(bmats.Bx10519.data[0][0])*bmats.Bx10519.shape[0]*bmats.Bx10519.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10519, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
