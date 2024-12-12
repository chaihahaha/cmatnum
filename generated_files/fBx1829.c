#include "stdafx.h"
#include "fBx1829.h"

inline int fBx1829(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_14, bmats.B_5_4, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1829.data[0][0], 0, sizeof(bmats.Bx1829.data[0][0])*bmats.Bx1829.shape[0]*bmats.Bx1829.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1829, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
