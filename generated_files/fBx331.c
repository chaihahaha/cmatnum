#include "stdafx.h"
#include "fBx331.h"

inline int fBx331(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_17, bmats.B_17_15, };
    double B_coeffs[2] = {-1, 1, };
memset(&bmats.Bx331.data[0][0], 0, sizeof(bmats.Bx331.data[0][0])*bmats.Bx331.shape[0]*bmats.Bx331.shape[1]);
    matlincomb_double_contiguous(bmats.Bx331, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}