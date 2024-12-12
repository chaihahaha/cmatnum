#include "stdafx.h"
#include "fBx337.h"

inline int fBx337(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_25, bmats.B_9_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx337.data[0][0], 0, sizeof(bmats.Bx337.data[0][0])*bmats.Bx337.shape[0]*bmats.Bx337.shape[1]);
    matlincomb_double_contiguous(bmats.Bx337, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
