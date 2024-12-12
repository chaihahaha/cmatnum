#include "stdafx.h"
#include "fBx8934.h"

inline int fBx8934(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_25, bmats.B_24_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8934.data[0][0], 0, sizeof(bmats.Bx8934.data[0][0])*bmats.Bx8934.shape[0]*bmats.Bx8934.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8934, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
