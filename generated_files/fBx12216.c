#include "stdafx.h"
#include "fBx12216.h"

inline int fBx12216(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_20_15, bmats.B_20_16, bmats.B_20_3, bmats.B_20_4, bmats.Bx11849, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12216.data[0][0], 0, sizeof(bmats.Bx12216.data[0][0])*bmats.Bx12216.shape[0]*bmats.Bx12216.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12216, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
