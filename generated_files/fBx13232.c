#include "stdafx.h"
#include "fBx13232.h"

inline int fBx13232(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_16, bmats.B_1_16, bmats.B_8_16, bmats.B_9_16, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13232.data[0][0], 0, sizeof(bmats.Bx13232.data[0][0])*bmats.Bx13232.shape[0]*bmats.Bx13232.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13232, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
