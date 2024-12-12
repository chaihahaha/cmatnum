#include "stdafx.h"
#include "fBx2783.h"

inline int fBx2783(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_20, bmats.B_4_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2783.data[0][0], 0, sizeof(bmats.Bx2783.data[0][0])*bmats.Bx2783.shape[0]*bmats.Bx2783.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2783, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
