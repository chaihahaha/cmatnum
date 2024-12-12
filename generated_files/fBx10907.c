#include "stdafx.h"
#include "fBx10907.h"

inline int fBx10907(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_10_22, bmats.B_12_22, bmats.B_13_22, bmats.B_7_22, bmats.B_8_22, bmats.B_9_22, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10907.data[0][0], 0, sizeof(bmats.Bx10907.data[0][0])*bmats.Bx10907.shape[0]*bmats.Bx10907.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10907, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
