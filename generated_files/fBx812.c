#include "stdafx.h"
#include "fBx812.h"

inline int fBx812(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_14, bmats.B_15_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx812.data[0][0], 0, sizeof(bmats.Bx812.data[0][0])*bmats.Bx812.shape[0]*bmats.Bx812.shape[1]);
    matlincomb_double_contiguous(bmats.Bx812, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
