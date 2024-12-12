#include "stdafx.h"
#include "fBx10065.h"

inline int fBx10065(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_18, bmats.B_18_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10065.data[0][0], 0, sizeof(bmats.Bx10065.data[0][0])*bmats.Bx10065.shape[0]*bmats.Bx10065.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10065, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
