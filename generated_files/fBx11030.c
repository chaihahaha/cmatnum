#include "stdafx.h"
#include "fBx11030.h"

inline int fBx11030(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_6, bmats.B_12_6, bmats.B_13_6, bmats.B_6_6, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11030.data[0][0], 0, sizeof(bmats.Bx11030.data[0][0])*bmats.Bx11030.shape[0]*bmats.Bx11030.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11030, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
