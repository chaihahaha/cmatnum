#include "stdafx.h"
#include "fBx5582.h"

inline int fBx5582(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_28, bmats.B_21_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5582.data[0][0], 0, sizeof(bmats.Bx5582.data[0][0])*bmats.Bx5582.shape[0]*bmats.Bx5582.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5582, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
