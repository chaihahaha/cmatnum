#include "stdafx.h"
#include "fBx1471.h"

inline int fBx1471(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_14, bmats.B_8_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1471.data[0][0], 0, sizeof(bmats.Bx1471.data[0][0])*bmats.Bx1471.shape[0]*bmats.Bx1471.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1471, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}