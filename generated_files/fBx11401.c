#include "stdafx.h"
#include "fBx11401.h"

inline int fBx11401(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_6_20, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx11401.data[0][0], 0, sizeof(bmats.Bx11401.data[0][0])*bmats.Bx11401.shape[0]*bmats.Bx11401.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11401, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}