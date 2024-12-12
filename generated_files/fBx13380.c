#include "stdafx.h"
#include "fBx13380.h"

inline int fBx13380(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_29_27, bmats.B_29_28, bmats.Bx1353, bmats.Bx4622, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13380.data[0][0], 0, sizeof(bmats.Bx13380.data[0][0])*bmats.Bx13380.shape[0]*bmats.Bx13380.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13380, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
