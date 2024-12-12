#include "stdafx.h"
#include "fBx5600.h"

inline int fBx5600(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_12, bmats.B_5_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5600.data[0][0], 0, sizeof(bmats.Bx5600.data[0][0])*bmats.Bx5600.shape[0]*bmats.Bx5600.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5600, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
