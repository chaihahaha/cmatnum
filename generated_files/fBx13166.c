#include "stdafx.h"
#include "fBx13166.h"

inline int fBx13166(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_16, bmats.B_16_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13166.data[0][0], 0, sizeof(bmats.Bx13166.data[0][0])*bmats.Bx13166.shape[0]*bmats.Bx13166.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13166, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}