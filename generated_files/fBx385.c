#include "stdafx.h"
#include "fBx385.h"

inline int fBx385(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_31, bmats.B_17_10, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx385.data[0][0], 0, sizeof(bmats.Bx385.data[0][0])*bmats.Bx385.shape[0]*bmats.Bx385.shape[1]);
    matlincomb_double_contiguous(bmats.Bx385, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
