#include "stdafx.h"
#include "fBx11326.h"

inline int fBx11326(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_6, bmats.B_2_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11326.data[0][0], 0, sizeof(bmats.Bx11326.data[0][0])*bmats.Bx11326.shape[0]*bmats.Bx11326.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11326, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}