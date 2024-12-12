#include "stdafx.h"
#include "fBx1060.h"

inline int fBx1060(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_11, bmats.B_11_13, bmats.B_11_3, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx1060.data[0][0], 0, sizeof(bmats.Bx1060.data[0][0])*bmats.Bx1060.shape[0]*bmats.Bx1060.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1060, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
