#include "stdafx.h"
#include "fBx13430.h"

inline int fBx13430(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_17_31, bmats.B_29_31, bmats.Bx13391, bmats.Bx13394, bmats.Bx13429, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13430.data[0][0], 0, sizeof(bmats.Bx13430.data[0][0])*bmats.Bx13430.shape[0]*bmats.Bx13430.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13430, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
