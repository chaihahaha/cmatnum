#include "stdafx.h"
#include "fBx5630.h"

inline int fBx5630(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx5629, bmats.Bx965, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5630.data[0][0], 0, sizeof(bmats.Bx5630.data[0][0])*bmats.Bx5630.shape[0]*bmats.Bx5630.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5630, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
