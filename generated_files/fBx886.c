#include "stdafx.h"
#include "fBx886.h"

inline int fBx886(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_24, bmats.B_8_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx886.data[0][0], 0, sizeof(bmats.Bx886.data[0][0])*bmats.Bx886.shape[0]*bmats.Bx886.shape[1]);
    matlincomb_double_contiguous(bmats.Bx886, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}