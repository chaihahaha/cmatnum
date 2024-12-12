#include "stdafx.h"
#include "fBx11386.h"

inline int fBx11386(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_6, bmats.B_3_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11386.data[0][0], 0, sizeof(bmats.Bx11386.data[0][0])*bmats.Bx11386.shape[0]*bmats.Bx11386.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11386, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
