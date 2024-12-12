#include "stdafx.h"
#include "fBx11991.h"

inline int fBx11991(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_16, bmats.B_32_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11991.data[0][0], 0, sizeof(bmats.Bx11991.data[0][0])*bmats.Bx11991.shape[0]*bmats.Bx11991.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11991, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
