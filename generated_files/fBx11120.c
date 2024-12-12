#include "stdafx.h"
#include "fBx11120.h"

inline int fBx11120(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_4, bmats.Bx7764, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11120.data[0][0], 0, sizeof(bmats.Bx11120.data[0][0])*bmats.Bx11120.shape[0]*bmats.Bx11120.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11120, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
