#include "stdafx.h"
#include "fBx10069.h"

inline int fBx10069(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_22, bmats.B_22_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10069.data[0][0], 0, sizeof(bmats.Bx10069.data[0][0])*bmats.Bx10069.shape[0]*bmats.Bx10069.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10069, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
