#include "stdafx.h"
#include "fBx11992.h"

inline int fBx11992(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_15, bmats.B_31_5, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11992.data[0][0], 0, sizeof(bmats.Bx11992.data[0][0])*bmats.Bx11992.shape[0]*bmats.Bx11992.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11992, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
