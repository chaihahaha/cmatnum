#include "stdafx.h"
#include "fBx11312.h"

inline int fBx11312(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_22, bmats.Bx10792, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11312.data[0][0], 0, sizeof(bmats.Bx11312.data[0][0])*bmats.Bx11312.shape[0]*bmats.Bx11312.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11312, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}