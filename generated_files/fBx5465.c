#include "stdafx.h"
#include "fBx5465.h"

inline int fBx5465(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_12, bmats.B_4_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5465.data[0][0], 0, sizeof(bmats.Bx5465.data[0][0])*bmats.Bx5465.shape[0]*bmats.Bx5465.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5465, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
