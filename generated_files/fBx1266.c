#include "stdafx.h"
#include "fBx1266.h"

inline int fBx1266(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_30, bmats.B_28_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1266.data[0][0], 0, sizeof(bmats.Bx1266.data[0][0])*bmats.Bx1266.shape[0]*bmats.Bx1266.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1266, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
