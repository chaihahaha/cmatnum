#include "stdafx.h"
#include "fBx11454.h"

inline int fBx11454(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_20_5, bmats.Bx11451, bmats.Bx11453, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11454.data[0][0], 0, sizeof(bmats.Bx11454.data[0][0])*bmats.Bx11454.shape[0]*bmats.Bx11454.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11454, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
