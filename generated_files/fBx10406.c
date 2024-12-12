#include "stdafx.h"
#include "fBx10406.h"

inline int fBx10406(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_7_23, bmats.Bx10405, bmats.Bx9668, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10406.data[0][0], 0, sizeof(bmats.Bx10406.data[0][0])*bmats.Bx10406.shape[0]*bmats.Bx10406.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10406, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
