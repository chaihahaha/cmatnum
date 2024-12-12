#include "stdafx.h"
#include "fBx10307.h"

inline int fBx10307(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_18, bmats.Bx10306, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10307.data[0][0], 0, sizeof(bmats.Bx10307.data[0][0])*bmats.Bx10307.shape[0]*bmats.Bx10307.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10307, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
