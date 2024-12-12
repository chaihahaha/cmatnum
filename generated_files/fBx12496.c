#include "stdafx.h"
#include "fBx12496.h"

inline int fBx12496(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_29_20, bmats.Bx10231, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12496.data[0][0], 0, sizeof(bmats.Bx12496.data[0][0])*bmats.Bx12496.shape[0]*bmats.Bx12496.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12496, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
