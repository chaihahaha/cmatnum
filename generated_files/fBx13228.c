#include "stdafx.h"
#include "fBx13228.h"

inline int fBx13228(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10273, bmats.Bx10922, bmats.Bx11459, bmats.Bx11919, bmats.Bx12437, bmats.Bx12683, bmats.Bx12874, bmats.Bx13224, bmats.Bx13225, bmats.Bx13227, bmats.Bx2531, bmats.Bx4259, bmats.Bx6005, bmats.Bx7232, bmats.Bx824, bmats.Bx8300, bmats.Bx9235, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13228.data[0][0], 0, sizeof(bmats.Bx13228.data[0][0])*bmats.Bx13228.shape[0]*bmats.Bx13228.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13228, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
