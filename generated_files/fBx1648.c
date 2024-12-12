#include "stdafx.h"
#include "fBx1648.h"

inline int fBx1648(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_30, bmats.B_25_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1648.data[0][0], 0, sizeof(bmats.Bx1648.data[0][0])*bmats.Bx1648.shape[0]*bmats.Bx1648.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1648, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
