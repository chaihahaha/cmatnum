#include "stdafx.h"
#include "fBx11656.h"

inline int fBx11656(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11547, bmats.Bx11624, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11656.data[0][0], 0, sizeof(bmats.Bx11656.data[0][0])*bmats.Bx11656.shape[0]*bmats.Bx11656.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11656, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}