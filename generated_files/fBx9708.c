#include "stdafx.h"
#include "fBx9708.h"

inline int fBx9708(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_8_16, bmats.Bx3807, bmats.Bx8916, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9708.data[0][0], 0, sizeof(bmats.Bx9708.data[0][0])*bmats.Bx9708.shape[0]*bmats.Bx9708.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9708, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}