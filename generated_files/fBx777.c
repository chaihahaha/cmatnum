#include "stdafx.h"
#include "fBx777.h"

inline int fBx777(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_30, bmats.B_30_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx777.data[0][0], 0, sizeof(bmats.Bx777.data[0][0])*bmats.Bx777.shape[0]*bmats.Bx777.shape[1]);
    matlincomb_double_contiguous(bmats.Bx777, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
