#include "stdafx.h"
#include "fBx10134.h"

inline int fBx10134(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_2, bmats.B_2_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10134.data[0][0], 0, sizeof(bmats.Bx10134.data[0][0])*bmats.Bx10134.shape[0]*bmats.Bx10134.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10134, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}