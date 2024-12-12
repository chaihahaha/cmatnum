#include "stdafx.h"
#include "fBx3784.h"

inline int fBx3784(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_13, bmats.B_7_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3784.data[0][0], 0, sizeof(bmats.Bx3784.data[0][0])*bmats.Bx3784.shape[0]*bmats.Bx3784.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3784, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
