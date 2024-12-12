#include "stdafx.h"
#include "fBx9218.h"

inline int fBx9218(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_8, bmats.B_12_8, bmats.B_13_8, bmats.B_14_8, bmats.B_8_8, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx9218.data[0][0], 0, sizeof(bmats.Bx9218.data[0][0])*bmats.Bx9218.shape[0]*bmats.Bx9218.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9218, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
