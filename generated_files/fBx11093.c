#include "stdafx.h"
#include "fBx11093.h"

inline int fBx11093(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_26_19, bmats.B_26_20, bmats.Bx4782, bmats.Bx7697, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11093.data[0][0], 0, sizeof(bmats.Bx11093.data[0][0])*bmats.Bx11093.shape[0]*bmats.Bx11093.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11093, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
