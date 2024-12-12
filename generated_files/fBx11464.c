#include "stdafx.h"
#include "fBx11464.h"

inline int fBx11464(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_21, bmats.B_18_21, bmats.B_19_21, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx11464.data[0][0], 0, sizeof(bmats.Bx11464.data[0][0])*bmats.Bx11464.shape[0]*bmats.Bx11464.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11464, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
