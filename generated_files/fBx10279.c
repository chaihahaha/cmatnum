#include "stdafx.h"
#include "fBx10279.h"

inline int fBx10279(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_19_23, bmats.Bx10035, bmats.Bx10233, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10279.data[0][0], 0, sizeof(bmats.Bx10279.data[0][0])*bmats.Bx10279.shape[0]*bmats.Bx10279.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10279, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
