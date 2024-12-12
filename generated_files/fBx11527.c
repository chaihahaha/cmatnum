#include "stdafx.h"
#include "fBx11527.h"

inline int fBx11527(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_21, bmats.B_5_21, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11527.data[0][0], 0, sizeof(bmats.Bx11527.data[0][0])*bmats.Bx11527.shape[0]*bmats.Bx11527.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11527, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
