#include "stdafx.h"
#include "fBx992.h"

inline int fBx992(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_30, bmats.B_32_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx992.data[0][0], 0, sizeof(bmats.Bx992.data[0][0])*bmats.Bx992.shape[0]*bmats.Bx992.shape[1]);
    matlincomb_double_contiguous(bmats.Bx992, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}