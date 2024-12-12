#include "stdafx.h"
#include "fBx10649.h"

inline int fBx10649(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_6, bmats.B_6_23, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10649.data[0][0], 0, sizeof(bmats.Bx10649.data[0][0])*bmats.Bx10649.shape[0]*bmats.Bx10649.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10649, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
