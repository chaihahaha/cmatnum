#include "stdafx.h"
#include "fBx1871.h"

inline int fBx1871(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_30, bmats.B_21_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1871.data[0][0], 0, sizeof(bmats.Bx1871.data[0][0])*bmats.Bx1871.shape[0]*bmats.Bx1871.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1871, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}