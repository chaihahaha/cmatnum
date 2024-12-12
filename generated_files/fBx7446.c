#include "stdafx.h"
#include "fBx7446.h"

inline int fBx7446(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_29_17, bmats.B_29_18, bmats.B_29_19, bmats.B_29_20, bmats.B_29_21, bmats.B_29_22, bmats.B_29_23, bmats.Bx3046, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7446.data[0][0], 0, sizeof(bmats.Bx7446.data[0][0])*bmats.Bx7446.shape[0]*bmats.Bx7446.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7446, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
