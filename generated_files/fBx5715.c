#include "stdafx.h"
#include "fBx5715.h"

inline int fBx5715(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_6, bmats.B_6_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5715.data[0][0], 0, sizeof(bmats.Bx5715.data[0][0])*bmats.Bx5715.shape[0]*bmats.Bx5715.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5715, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}