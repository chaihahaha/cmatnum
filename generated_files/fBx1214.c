#include "stdafx.h"
#include "fBx1214.h"

inline int fBx1214(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_9, bmats.Bx1213, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1214.data[0][0], 0, sizeof(bmats.Bx1214.data[0][0])*bmats.Bx1214.shape[0]*bmats.Bx1214.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1214, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}