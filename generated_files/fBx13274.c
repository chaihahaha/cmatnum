#include "stdafx.h"
#include "fBx13274.h"

inline int fBx13274(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10258, bmats.Bx10384, bmats.Bx11247, bmats.Bx11720, bmats.Bx12139, bmats.Bx12503, bmats.Bx12804, bmats.Bx13005, bmats.Bx13272, bmats.Bx13273, bmats.Bx1400, bmats.Bx3722, bmats.Bx5109, bmats.Bx6342, bmats.Bx7450, bmats.Bx8852, bmats.Bx9639, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13274.data[0][0], 0, sizeof(bmats.Bx13274.data[0][0])*bmats.Bx13274.shape[0]*bmats.Bx13274.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13274, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
