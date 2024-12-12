#include "stdafx.h"
#include "fBx672.h"

inline int fBx672(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_30, bmats.B_30_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx672.data[0][0], 0, sizeof(bmats.Bx672.data[0][0])*bmats.Bx672.shape[0]*bmats.Bx672.shape[1]);
    matlincomb_double_contiguous(bmats.Bx672, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
