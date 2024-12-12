#include "stdafx.h"
#include "fBx10449.h"

inline int fBx10449(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_8_17, bmats.B_8_18, bmats.B_8_19, bmats.B_8_20, bmats.B_8_21, bmats.Bx9729, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10449.data[0][0], 0, sizeof(bmats.Bx10449.data[0][0])*bmats.Bx10449.shape[0]*bmats.Bx10449.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10449, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
