#include "stdafx.h"
#include "fBx13136.h"

inline int fBx13136(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_6_8, bmats.B_8_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13136.data[0][0], 0, sizeof(bmats.Bx13136.data[0][0])*bmats.Bx13136.shape[0]*bmats.Bx13136.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13136, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}