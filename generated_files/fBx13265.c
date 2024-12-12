#include "stdafx.h"
#include "fBx13265.h"

inline int fBx13265(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10535, bmats.Bx11122, bmats.Bx11447, bmats.Bx11689, bmats.Bx12242, bmats.Bx12541, bmats.Bx12789, bmats.Bx12991, bmats.Bx13263, bmats.Bx13264, bmats.Bx1831, bmats.Bx3544, bmats.Bx5513, bmats.Bx6703, bmats.Bx7766, bmats.Bx8734, bmats.Bx9911, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13265.data[0][0], 0, sizeof(bmats.Bx13265.data[0][0])*bmats.Bx13265.shape[0]*bmats.Bx13265.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13265, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
