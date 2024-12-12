#include "stdafx.h"
#include "fBx6177.h"

inline int fBx6177(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_20, bmats.B_20_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6177.data[0][0], 0, sizeof(bmats.Bx6177.data[0][0])*bmats.Bx6177.shape[0]*bmats.Bx6177.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6177, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
