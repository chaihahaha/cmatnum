#include "stdafx.h"
#include "fBx5919.h"

inline int fBx5919(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_28, bmats.Bx3894, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5919.data[0][0], 0, sizeof(bmats.Bx5919.data[0][0])*bmats.Bx5919.shape[0]*bmats.Bx5919.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5919, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
