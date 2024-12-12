#include "stdafx.h"
#include "fBx13051.h"

inline int fBx13051(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_17, bmats.B_17_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13051.data[0][0], 0, sizeof(bmats.Bx13051.data[0][0])*bmats.Bx13051.shape[0]*bmats.Bx13051.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13051, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
