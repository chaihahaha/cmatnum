#include "stdafx.h"
#include "fBx3835.h"

inline int fBx3835(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_8_13, bmats.B_8_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3835.data[0][0], 0, sizeof(bmats.Bx3835.data[0][0])*bmats.Bx3835.shape[0]*bmats.Bx3835.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3835, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
