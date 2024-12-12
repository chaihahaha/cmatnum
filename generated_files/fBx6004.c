#include "stdafx.h"
#include "fBx6004.h"

inline int fBx6004(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_11, bmats.B_2_11, bmats.B_3_11, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx6004.data[0][0], 0, sizeof(bmats.Bx6004.data[0][0])*bmats.Bx6004.shape[0]*bmats.Bx6004.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6004, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
