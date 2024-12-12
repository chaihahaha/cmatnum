#include "stdafx.h"
#include "fBx3069.h"

inline int fBx3069(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_28, bmats.B_13_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3069.data[0][0], 0, sizeof(bmats.Bx3069.data[0][0])*bmats.Bx3069.shape[0]*bmats.Bx3069.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3069, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
