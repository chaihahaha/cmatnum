#include "stdafx.h"
#include "fBx11506.h"

inline int fBx11506(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_5, bmats.B_16_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11506.data[0][0], 0, sizeof(bmats.Bx11506.data[0][0])*bmats.Bx11506.shape[0]*bmats.Bx11506.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11506, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
