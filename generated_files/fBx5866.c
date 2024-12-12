#include "stdafx.h"
#include "fBx5866.h"

inline int fBx5866(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_16, bmats.B_32_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5866.data[0][0], 0, sizeof(bmats.Bx5866.data[0][0])*bmats.Bx5866.shape[0]*bmats.Bx5866.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5866, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
