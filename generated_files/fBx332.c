#include "stdafx.h"
#include "fBx332.h"

inline int fBx332(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_21, bmats.B_5_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx332.data[0][0], 0, sizeof(bmats.Bx332.data[0][0])*bmats.Bx332.shape[0]*bmats.Bx332.shape[1]);
    matlincomb_double_contiguous(bmats.Bx332, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
