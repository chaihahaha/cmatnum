#include "stdafx.h"
#include "fBx9534.h"

inline int fBx9534(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_8_8, bmats.Bx9468, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9534.data[0][0], 0, sizeof(bmats.Bx9534.data[0][0])*bmats.Bx9534.shape[0]*bmats.Bx9534.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9534, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
