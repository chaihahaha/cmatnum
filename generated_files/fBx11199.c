#include "stdafx.h"
#include "fBx11199.h"

inline int fBx11199(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_4, bmats.Bx10604, bmats.Bx3573, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11199.data[0][0], 0, sizeof(bmats.Bx11199.data[0][0])*bmats.Bx11199.shape[0]*bmats.Bx11199.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11199, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
