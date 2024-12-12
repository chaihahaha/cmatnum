#include "stdafx.h"
#include "fBx258.h"

inline int fBx258(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_9, bmats.B_9_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx258.data[0][0], 0, sizeof(bmats.Bx258.data[0][0])*bmats.Bx258.shape[0]*bmats.Bx258.shape[1]);
    matlincomb_double_contiguous(bmats.Bx258, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
