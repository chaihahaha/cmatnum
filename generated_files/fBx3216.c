#include "stdafx.h"
#include "fBx3216.h"

inline int fBx3216(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_29, bmats.B_25_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3216.data[0][0], 0, sizeof(bmats.Bx3216.data[0][0])*bmats.Bx3216.shape[0]*bmats.Bx3216.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3216, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
