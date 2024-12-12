#include "stdafx.h"
#include "fBx11715.h"

inline int fBx11715(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_10_21, bmats.B_11_21, bmats.B_12_21, bmats.B_13_21, bmats.B_6_21, bmats.Bx11441, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11715.data[0][0], 0, sizeof(bmats.Bx11715.data[0][0])*bmats.Bx11715.shape[0]*bmats.Bx11715.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11715, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
