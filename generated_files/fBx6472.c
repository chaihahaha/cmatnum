#include "stdafx.h"
#include "fBx6472.h"

inline int fBx6472(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_8_25, bmats.B_9_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6472.data[0][0], 0, sizeof(bmats.Bx6472.data[0][0])*bmats.Bx6472.shape[0]*bmats.Bx6472.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6472, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
