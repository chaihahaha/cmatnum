#include "stdafx.h"
#include "fBx13259.h"

inline int fBx13259(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10464, bmats.Bx11105, bmats.Bx11821, bmats.Bx12055, bmats.Bx12234, bmats.Bx12524, bmats.Bx12786, bmats.Bx13022, bmats.Bx13257, bmats.Bx13258, bmats.Bx1800, bmats.Bx4055, bmats.Bx5408, bmats.Bx6606, bmats.Bx7740, bmats.Bx9089, bmats.Bx9840, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13259.data[0][0], 0, sizeof(bmats.Bx13259.data[0][0])*bmats.Bx13259.shape[0]*bmats.Bx13259.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13259, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
