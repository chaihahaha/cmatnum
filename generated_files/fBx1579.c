#include "stdafx.h"
#include "fBx1579.h"

inline int fBx1579(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_30, bmats.B_25_23, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1579.data[0][0], 0, sizeof(bmats.Bx1579.data[0][0])*bmats.Bx1579.shape[0]*bmats.Bx1579.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1579, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
