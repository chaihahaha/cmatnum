#include "stdafx.h"
#include "fBx13271.h"

inline int fBx13271(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10606, bmats.Bx10912, bmats.Bx11231, bmats.Bx11700, bmats.Bx12133, bmats.Bx12550, bmats.Bx12796, bmats.Bx12994, bmats.Bx13269, bmats.Bx13270, bmats.Bx1953, bmats.Bx3575, bmats.Bx4981, bmats.Bx6297, bmats.Bx7856, bmats.Bx8757, bmats.Bx9603, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13271.data[0][0], 0, sizeof(bmats.Bx13271.data[0][0])*bmats.Bx13271.shape[0]*bmats.Bx13271.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13271, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
