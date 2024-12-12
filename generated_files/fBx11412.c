#include "stdafx.h"
#include "fBx11412.h"

inline int fBx11412(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_22, bmats.B_20_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11412.data[0][0], 0, sizeof(bmats.Bx11412.data[0][0])*bmats.Bx11412.shape[0]*bmats.Bx11412.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11412, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
