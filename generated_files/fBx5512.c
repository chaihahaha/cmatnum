#include "stdafx.h"
#include "fBx5512.h"

inline int fBx5512(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_5_13, bmats.B_5_16, bmats.B_5_8, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx5512.data[0][0], 0, sizeof(bmats.Bx5512.data[0][0])*bmats.Bx5512.shape[0]*bmats.Bx5512.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5512, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
