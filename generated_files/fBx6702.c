#include "stdafx.h"
#include "fBx6702.h"

inline int fBx6702(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_10, bmats.Bx1859, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6702.data[0][0], 0, sizeof(bmats.Bx6702.data[0][0])*bmats.Bx6702.shape[0]*bmats.Bx6702.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6702, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}