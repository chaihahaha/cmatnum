#include "stdafx.h"
#include "fBx5664.h"

inline int fBx5664(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_28_11, bmats.B_29_11, bmats.B_30_11, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx5664.data[0][0], 0, sizeof(bmats.Bx5664.data[0][0])*bmats.Bx5664.shape[0]*bmats.Bx5664.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5664, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
