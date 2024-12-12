#include "stdafx.h"
#include "fBx5752.h"

inline int fBx5752(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_20, bmats.B_20_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5752.data[0][0], 0, sizeof(bmats.Bx5752.data[0][0])*bmats.Bx5752.shape[0]*bmats.Bx5752.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5752, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
