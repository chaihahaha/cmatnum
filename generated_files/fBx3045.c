#include "stdafx.h"
#include "fBx3045.h"

inline int fBx3045(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_29, bmats.B_29_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3045.data[0][0], 0, sizeof(bmats.Bx3045.data[0][0])*bmats.Bx3045.shape[0]*bmats.Bx3045.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3045, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}