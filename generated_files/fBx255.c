#include "stdafx.h"
#include "fBx255.h"

inline int fBx255(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_30, bmats.B_32_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx255.data[0][0], 0, sizeof(bmats.Bx255.data[0][0])*bmats.Bx255.shape[0]*bmats.Bx255.shape[1]);
    matlincomb_double_contiguous(bmats.Bx255, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
