#include "stdafx.h"
#include "fBx12375.h"

inline int fBx12375(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_4, bmats.Bx11733, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12375.data[0][0], 0, sizeof(bmats.Bx12375.data[0][0])*bmats.Bx12375.shape[0]*bmats.Bx12375.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12375, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}