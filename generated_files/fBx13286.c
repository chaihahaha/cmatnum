#include "stdafx.h"
#include "fBx13286.h"

inline int fBx13286(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10454, bmats.Bx11089, bmats.Bx11651, bmats.Bx12106, bmats.Bx12518, bmats.Bx12777, bmats.Bx12976, bmats.Bx13284, bmats.Bx13285, bmats.Bx1616, bmats.Bx3241, bmats.Bx4695, bmats.Bx6529, bmats.Bx7605, bmats.Bx8272, bmats.Bx8604, bmats.Bx9521, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13286.data[0][0], 0, sizeof(bmats.Bx13286.data[0][0])*bmats.Bx13286.shape[0]*bmats.Bx13286.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13286, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
