#include "stdafx.h"
#include "fBx298.h"

inline int fBx298(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_15, bmats.B_15_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx298.data[0][0], 0, sizeof(bmats.Bx298.data[0][0])*bmats.Bx298.shape[0]*bmats.Bx298.shape[1]);
    matlincomb_double_contiguous(bmats.Bx298, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}