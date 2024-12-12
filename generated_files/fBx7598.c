#include "stdafx.h"
#include "fBx7598.h"

inline int fBx7598(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_10, bmats.B_9_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7598.data[0][0], 0, sizeof(bmats.Bx7598.data[0][0])*bmats.Bx7598.shape[0]*bmats.Bx7598.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7598, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
