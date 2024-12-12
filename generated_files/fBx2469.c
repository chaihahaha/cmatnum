#include "stdafx.h"
#include "fBx2469.h"

inline int fBx2469(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_25, bmats.B_9_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2469.data[0][0], 0, sizeof(bmats.Bx2469.data[0][0])*bmats.Bx2469.shape[0]*bmats.Bx2469.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2469, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
