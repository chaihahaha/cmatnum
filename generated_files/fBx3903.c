#include "stdafx.h"
#include "fBx3903.h"

inline int fBx3903(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_7, bmats.B_7_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3903.data[0][0], 0, sizeof(bmats.Bx3903.data[0][0])*bmats.Bx3903.shape[0]*bmats.Bx3903.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3903, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
