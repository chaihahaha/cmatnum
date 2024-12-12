#include "stdafx.h"
#include "fBx770.h"

inline int fBx770(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_14, bmats.B_14_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx770.data[0][0], 0, sizeof(bmats.Bx770.data[0][0])*bmats.Bx770.shape[0]*bmats.Bx770.shape[1]);
    matlincomb_double_contiguous(bmats.Bx770, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
