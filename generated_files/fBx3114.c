#include "stdafx.h"
#include "fBx3114.h"

inline int fBx3114(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx2482, bmats.Bx3113, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3114.data[0][0], 0, sizeof(bmats.Bx3114.data[0][0])*bmats.Bx3114.shape[0]*bmats.Bx3114.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3114, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
