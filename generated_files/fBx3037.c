#include "stdafx.h"
#include "fBx3037.h"

inline int fBx3037(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_29_19, bmats.B_3_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3037.data[0][0], 0, sizeof(bmats.Bx3037.data[0][0])*bmats.Bx3037.shape[0]*bmats.Bx3037.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3037, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
