#include "stdafx.h"
#include "fBx5656.h"

inline int fBx5656(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_8, bmats.B_24_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5656.data[0][0], 0, sizeof(bmats.Bx5656.data[0][0])*bmats.Bx5656.shape[0]*bmats.Bx5656.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5656, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}