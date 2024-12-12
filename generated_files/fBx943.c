#include "stdafx.h"
#include "fBx943.h"

inline int fBx943(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_29_30, bmats.B_32_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx943.data[0][0], 0, sizeof(bmats.Bx943.data[0][0])*bmats.Bx943.shape[0]*bmats.Bx943.shape[1]);
    matlincomb_double_contiguous(bmats.Bx943, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
