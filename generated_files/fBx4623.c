#include "stdafx.h"
#include "fBx4623.h"

inline int fBx4623(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_29_31, bmats.B_29_32, bmats.Bx1353, bmats.Bx4622, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx4623.data[0][0], 0, sizeof(bmats.Bx4623.data[0][0])*bmats.Bx4623.shape[0]*bmats.Bx4623.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4623, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
