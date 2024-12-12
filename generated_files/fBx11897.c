#include "stdafx.h"
#include "fBx11897.h"

inline int fBx11897(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11895, bmats.Bx11896, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11897.data[0][0], 0, sizeof(bmats.Bx11897.data[0][0])*bmats.Bx11897.shape[0]*bmats.Bx11897.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11897, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
