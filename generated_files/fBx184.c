#include "stdafx.h"
#include "fBx184.h"

inline int fBx184(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_24, bmats.B_24_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx184.data[0][0], 0, sizeof(bmats.Bx184.data[0][0])*bmats.Bx184.shape[0]*bmats.Bx184.shape[1]);
    matlincomb_double_contiguous(bmats.Bx184, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
