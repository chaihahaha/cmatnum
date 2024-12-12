#include "stdafx.h"
#include "fBx6189.h"

inline int fBx6189(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_19, bmats.B_19_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6189.data[0][0], 0, sizeof(bmats.Bx6189.data[0][0])*bmats.Bx6189.shape[0]*bmats.Bx6189.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6189, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
