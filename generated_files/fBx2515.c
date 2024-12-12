#include "stdafx.h"
#include "fBx2515.h"

inline int fBx2515(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_20_13, bmats.B_22_13, bmats.B_28_13, bmats.Bx2508, bmats.Bx2509, bmats.Bx2510, bmats.Bx2511, bmats.Bx2513, bmats.Bx2514, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx2515.data[0][0], 0, sizeof(bmats.Bx2515.data[0][0])*bmats.Bx2515.shape[0]*bmats.Bx2515.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2515, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
