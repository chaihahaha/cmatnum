#include "stdafx.h"
#include "fBx13292.h"

inline int fBx13292(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx1013, bmats.Bx10336, bmats.Bx11095, bmats.Bx11660, bmats.Bx12121, bmats.Bx12467, bmats.Bx12784, bmats.Bx12983, bmats.Bx13290, bmats.Bx13291, bmats.Bx3356, bmats.Bx4798, bmats.Bx6125, bmats.Bx7219, bmats.Bx7690, bmats.Bx8677, bmats.Bx9542, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13292.data[0][0], 0, sizeof(bmats.Bx13292.data[0][0])*bmats.Bx13292.shape[0]*bmats.Bx13292.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13292, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
