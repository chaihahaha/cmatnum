#include "stdafx.h"
#include "fBx457.h"

inline int fBx457(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_18, bmats.B_18_15, };
    double B_coeffs[2] = {-1, 1, };
memset(&bmats.Bx457.data[0][0], 0, sizeof(bmats.Bx457.data[0][0])*bmats.Bx457.shape[0]*bmats.Bx457.shape[1]);
    matlincomb_double_contiguous(bmats.Bx457, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
