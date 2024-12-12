#include "stdafx.h"
#include "fBx3800.h"

inline int fBx3800(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_13, bmats.B_8_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3800.data[0][0], 0, sizeof(bmats.Bx3800.data[0][0])*bmats.Bx3800.shape[0]*bmats.Bx3800.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3800, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
