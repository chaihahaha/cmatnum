#include "stdafx.h"
#include "fBx10391.h"

inline int fBx10391(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_23_24, bmats.B_23_32, bmats.Bx2086, bmats.Bx8863, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx10391.data[0][0], 0, sizeof(bmats.Bx10391.data[0][0])*bmats.Bx10391.shape[0]*bmats.Bx10391.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10391, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
