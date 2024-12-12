#include "stdafx.h"
#include "fBx13223.h"

inline int fBx13223(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx10288, bmats.Bx10934, bmats.Bx11474, bmats.Bx11900, bmats.Bx12446, bmats.Bx12694, bmats.Bx12883, bmats.Bx13216, bmats.Bx13222, bmats.Bx2560, bmats.Bx4199, bmats.Bx6028, bmats.Bx7254, bmats.Bx8318, bmats.Bx854, bmats.Bx9185, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13223.data[0][0], 0, sizeof(bmats.Bx13223.data[0][0])*bmats.Bx13223.shape[0]*bmats.Bx13223.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13223, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
