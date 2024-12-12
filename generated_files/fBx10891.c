#include "stdafx.h"
#include "fBx10891.h"

inline int fBx10891(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_15_6, bmats.B_16_6, bmats.B_1_6, bmats.B_2_6, bmats.B_4_6, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx10891.data[0][0], 0, sizeof(bmats.Bx10891.data[0][0])*bmats.Bx10891.shape[0]*bmats.Bx10891.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10891, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
