#include "stdafx.h"
#include "fBx5122.h"

inline int fBx5122(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_28, bmats.Bx3736, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5122.data[0][0], 0, sizeof(bmats.Bx5122.data[0][0])*bmats.Bx5122.shape[0]*bmats.Bx5122.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5122, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
