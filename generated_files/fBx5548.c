#include "stdafx.h"
#include "fBx5548.h"

inline int fBx5548(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_28, bmats.B_21_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5548.data[0][0], 0, sizeof(bmats.Bx5548.data[0][0])*bmats.Bx5548.shape[0]*bmats.Bx5548.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5548, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
