#include "stdafx.h"
#include "fBx13454.h"

inline int fBx13454(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_17_32, bmats.B_18_32, bmats.Bx13382, bmats.Bx13440, bmats.Bx13449, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13454.data[0][0], 0, sizeof(bmats.Bx13454.data[0][0])*bmats.Bx13454.shape[0]*bmats.Bx13454.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13454, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
