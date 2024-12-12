#include "stdafx.h"
#include "fBx3323.h"

inline int fBx3323(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_7, bmats.B_7_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3323.data[0][0], 0, sizeof(bmats.Bx3323.data[0][0])*bmats.Bx3323.shape[0]*bmats.Bx3323.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3323, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
