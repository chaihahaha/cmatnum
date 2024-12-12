#include "stdafx.h"
#include "fBx3109.h"

inline int fBx3109(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_15_13, bmats.B_6_13, bmats.Bx2499, bmats.Bx2501, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx3109.data[0][0], 0, sizeof(bmats.Bx3109.data[0][0])*bmats.Bx3109.shape[0]*bmats.Bx3109.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3109, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
