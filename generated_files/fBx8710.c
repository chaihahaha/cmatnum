#include "stdafx.h"
#include "fBx8710.h"

inline int fBx8710(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_16, bmats.B_32_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8710.data[0][0], 0, sizeof(bmats.Bx8710.data[0][0])*bmats.Bx8710.shape[0]*bmats.Bx8710.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8710, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
