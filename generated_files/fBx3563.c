#include "stdafx.h"
#include "fBx3563.h"

inline int fBx3563(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_6_7, bmats.B_7_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3563.data[0][0], 0, sizeof(bmats.Bx3563.data[0][0])*bmats.Bx3563.shape[0]*bmats.Bx3563.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3563, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}