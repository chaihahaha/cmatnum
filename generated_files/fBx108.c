#include "stdafx.h"
#include "fBx108.h"

inline int fBx108(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_26, bmats.B_26_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx108.data[0][0], 0, sizeof(bmats.Bx108.data[0][0])*bmats.Bx108.shape[0]*bmats.Bx108.shape[1]);
    matlincomb_double_contiguous(bmats.Bx108, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
