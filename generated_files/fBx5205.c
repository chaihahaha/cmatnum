#include "stdafx.h"
#include "fBx5205.h"

inline int fBx5205(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_12, bmats.B_8_4, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5205.data[0][0], 0, sizeof(bmats.Bx5205.data[0][0])*bmats.Bx5205.shape[0]*bmats.Bx5205.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5205, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}