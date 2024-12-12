#include "stdafx.h"
#include "fBx4963.h"

inline int fBx4963(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_26, bmats.B_26_12, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4963.data[0][0], 0, sizeof(bmats.Bx4963.data[0][0])*bmats.Bx4963.shape[0]*bmats.Bx4963.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4963, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
