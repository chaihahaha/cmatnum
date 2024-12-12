#include "stdafx.h"
#include "fBx10529.h"

inline int fBx10529(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_7, bmats.B_5_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10529.data[0][0], 0, sizeof(bmats.Bx10529.data[0][0])*bmats.Bx10529.shape[0]*bmats.Bx10529.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10529, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
