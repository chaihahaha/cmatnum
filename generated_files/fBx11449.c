#include "stdafx.h"
#include "fBx11449.h"

inline int fBx11449(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_5, bmats.B_18_5, bmats.B_31_5, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11449.data[0][0], 0, sizeof(bmats.Bx11449.data[0][0])*bmats.Bx11449.shape[0]*bmats.Bx11449.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11449, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}