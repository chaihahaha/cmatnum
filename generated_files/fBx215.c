#include "stdafx.h"
#include "fBx215.h"

inline int fBx215(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_24, bmats.B_23_21, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx215.data[0][0], 0, sizeof(bmats.Bx215.data[0][0])*bmats.Bx215.shape[0]*bmats.Bx215.shape[1]);
    matlincomb_double_contiguous(bmats.Bx215, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
