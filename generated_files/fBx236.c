#include "stdafx.h"
#include "fBx236.h"

inline int fBx236(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_21, bmats.B_5_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx236.data[0][0], 0, sizeof(bmats.Bx236.data[0][0])*bmats.Bx236.shape[0]*bmats.Bx236.shape[1]);
    matlincomb_double_contiguous(bmats.Bx236, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}