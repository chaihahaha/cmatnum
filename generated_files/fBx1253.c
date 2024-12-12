#include "stdafx.h"
#include "fBx1253.h"

inline int fBx1253(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_14, bmats.B_12_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1253.data[0][0], 0, sizeof(bmats.Bx1253.data[0][0])*bmats.Bx1253.shape[0]*bmats.Bx1253.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1253, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
