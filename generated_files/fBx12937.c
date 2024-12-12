#include "stdafx.h"
#include "fBx12937.h"

inline int fBx12937(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_18, bmats.B_1_32, bmats.Bx12810, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12937.data[0][0], 0, sizeof(bmats.Bx12937.data[0][0])*bmats.Bx12937.shape[0]*bmats.Bx12937.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12937, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
