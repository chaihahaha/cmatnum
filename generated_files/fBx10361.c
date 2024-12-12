#include "stdafx.h"
#include "fBx10361.h"

inline int fBx10361(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_13_10, bmats.Bx1306, bmats.Bx5954, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10361.data[0][0], 0, sizeof(bmats.Bx10361.data[0][0])*bmats.Bx10361.shape[0]*bmats.Bx10361.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10361, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
