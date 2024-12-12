#include "stdafx.h"
#include "fBx5202.h"

inline int fBx5202(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_12, bmats.B_8_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5202.data[0][0], 0, sizeof(bmats.Bx5202.data[0][0])*bmats.Bx5202.shape[0]*bmats.Bx5202.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5202, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
