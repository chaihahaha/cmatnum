#include "stdafx.h"
#include "fBx888.h"

inline int fBx888(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_10_14, bmats.B_15_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx888.data[0][0], 0, sizeof(bmats.Bx888.data[0][0])*bmats.Bx888.shape[0]*bmats.Bx888.shape[1]);
    matlincomb_double_contiguous(bmats.Bx888, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
