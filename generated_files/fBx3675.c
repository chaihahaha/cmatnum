#include "stdafx.h"
#include "fBx3675.h"

inline int fBx3675(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_13, bmats.B_6_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3675.data[0][0], 0, sizeof(bmats.Bx3675.data[0][0])*bmats.Bx3675.shape[0]*bmats.Bx3675.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3675, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}