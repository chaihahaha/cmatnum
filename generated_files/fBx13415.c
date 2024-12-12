#include "stdafx.h"
#include "fBx13415.h"

inline int fBx13415(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_17_31, bmats.B_28_31, bmats.B_32_31, bmats.Bx13391, bmats.Bx13394, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13415.data[0][0], 0, sizeof(bmats.Bx13415.data[0][0])*bmats.Bx13415.shape[0]*bmats.Bx13415.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13415, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
