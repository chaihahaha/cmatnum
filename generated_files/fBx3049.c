#include "stdafx.h"
#include "fBx3049.h"

inline int fBx3049(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_29, bmats.B_29_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3049.data[0][0], 0, sizeof(bmats.Bx3049.data[0][0])*bmats.Bx3049.shape[0]*bmats.Bx3049.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3049, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}