#include "stdafx.h"
#include "fBx6915.h"

inline int fBx6915(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_20, bmats.B_20_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6915.data[0][0], 0, sizeof(bmats.Bx6915.data[0][0])*bmats.Bx6915.shape[0]*bmats.Bx6915.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6915, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}