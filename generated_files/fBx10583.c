#include "stdafx.h"
#include "fBx10583.h"

inline int fBx10583(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_6, bmats.B_6_23, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10583.data[0][0], 0, sizeof(bmats.Bx10583.data[0][0])*bmats.Bx10583.shape[0]*bmats.Bx10583.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10583, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
