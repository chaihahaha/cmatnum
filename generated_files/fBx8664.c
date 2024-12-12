#include "stdafx.h"
#include "fBx8664.h"

inline int fBx8664(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_10_15, bmats.B_10_4, bmats.Bx1719, bmats.Bx3326, bmats.Bx4795, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx8664.data[0][0], 0, sizeof(bmats.Bx8664.data[0][0])*bmats.Bx8664.shape[0]*bmats.Bx8664.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8664, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
