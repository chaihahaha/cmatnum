#include "stdafx.h"
#include "fBx10976.h"

inline int fBx10976(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_22, bmats.B_32_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10976.data[0][0], 0, sizeof(bmats.Bx10976.data[0][0])*bmats.Bx10976.shape[0]*bmats.Bx10976.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10976, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
