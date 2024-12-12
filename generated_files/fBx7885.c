#include "stdafx.h"
#include "fBx7885.h"

inline int fBx7885(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_16, bmats.B_32_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7885.data[0][0], 0, sizeof(bmats.Bx7885.data[0][0])*bmats.Bx7885.shape[0]*bmats.Bx7885.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7885, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
