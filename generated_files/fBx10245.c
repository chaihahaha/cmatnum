#include "stdafx.h"
#include "fBx10245.h"

inline int fBx10245(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_23, bmats.Bx10021, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10245.data[0][0], 0, sizeof(bmats.Bx10245.data[0][0])*bmats.Bx10245.shape[0]*bmats.Bx10245.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10245, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
