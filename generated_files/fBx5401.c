#include "stdafx.h"
#include "fBx5401.h"

inline int fBx5401(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_5, bmats.B_5_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5401.data[0][0], 0, sizeof(bmats.Bx5401.data[0][0])*bmats.Bx5401.shape[0]*bmats.Bx5401.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5401, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}