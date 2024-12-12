#include "stdafx.h"
#include "fBx3016.h"

inline int fBx3016(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_29, bmats.B_29_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3016.data[0][0], 0, sizeof(bmats.Bx3016.data[0][0])*bmats.Bx3016.shape[0]*bmats.Bx3016.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3016, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
