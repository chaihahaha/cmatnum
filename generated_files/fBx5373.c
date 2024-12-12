#include "stdafx.h"
#include "fBx5373.h"

inline int fBx5373(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_28, bmats.B_19_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5373.data[0][0], 0, sizeof(bmats.Bx5373.data[0][0])*bmats.Bx5373.shape[0]*bmats.Bx5373.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5373, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
