#include "stdafx.h"
#include "fBx12603.h"

inline int fBx12603(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_19, bmats.B_18_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12603.data[0][0], 0, sizeof(bmats.Bx12603.data[0][0])*bmats.Bx12603.shape[0]*bmats.Bx12603.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12603, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}