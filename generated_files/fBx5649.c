#include "stdafx.h"
#include "fBx5649.h"

inline int fBx5649(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_27_27, bmats.B_28_27, bmats.B_30_27, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx5649.data[0][0], 0, sizeof(bmats.Bx5649.data[0][0])*bmats.Bx5649.shape[0]*bmats.Bx5649.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5649, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
